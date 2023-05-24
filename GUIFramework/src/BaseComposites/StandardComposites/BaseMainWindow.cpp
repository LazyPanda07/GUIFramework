#include "BaseMainWindow.h"

#include <windowsx.h>

#include "GUIFramework.h"
#include "Exceptions/CantFindFunctionFromModuleException.h"

using namespace std;

namespace gui_framework
{
	BaseMainWindow::Function::Function(const function<void()>& callable) :
		callable(callable)
	{

	}

	BaseMainWindow::Function::Function(const string& functionName, const string& moduleName) :
		functionName(functionName),
		moduleName(moduleName)
	{
		GUIFramework& instance = GUIFramework::get();
		const HMODULE& module = instance.getModules().at(moduleName);

		onClickSignature tem = reinterpret_cast<onClickSignature>(GetProcAddress(module, functionName.data()));

		if (!tem)
		{
			throw exceptions::CantFindFunctionFromModuleException(functionName, moduleName, __FILE__, __FUNCTION__, __LINE__);
		}

		callable = tem;
	}

	void BaseMainWindow::onDestroyEvent()
	{

	}

	LRESULT BaseMainWindow::windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		LRESULT result = BaseSeparateWindow::windowMessagesHandle(handle, message, wparam, lparam, isUsed);

		if (isUsed)
		{
			return result;
		}

		if (message == trayId)
		{
			switch (LOWORD(lparam))
			{
			case NIN_SELECT:
				isUsed = true;

				if (++clicks == 2)
				{
					Shell_NotifyIconW(NIM_DELETE, &tray);

					show();

					clicks = 0;
				}

				break;

			case WM_CONTEXTMENU:
				if (trayPopupMenu)
				{
					isUsed = true;

					TrackPopupMenuEx(trayPopupMenu, TPM_CENTERALIGN, GET_X_LPARAM(wparam), GET_Y_LPARAM(wparam), this->getHandle(), nullptr);
				}

				break;

			default:
				break;
			}
		}
		else if (message == WM_COMMAND && popupMenuItems.size())
		{
			uint32_t id = LOWORD(wparam);

			if (auto it = ranges::find_if(popupMenuItems, [id](const pair<uint32_t, Function>& item) { return item.first == id; }); it != popupMenuItems.end())
			{
				isUsed = true;

				it->second.callable();
			}
		}

		return -1;
	}

	BaseMainWindow::BaseMainWindow(const wstring& className, const wstring& titleName, const utility::ComponentSettings& settings, const string& windowFunctionName, uint16_t trayIconResource, bool maximize, bool minimize, const string& moduleName, uint16_t smallIconResource, uint16_t largeIconResource) :
		BaseSeparateWindow
		(
			className,
			titleName,
			settings,
			windowFunctionName,
			maximize,
			minimize,
			moduleName,
			smallIconResource,
			largeIconResource
		),
		tray(),
		trayPopupMenu(nullptr),
		trayId(0),
		clicks(0),
		trayIconResource(trayIconResource)
	{
		// TODO: localization

		this->setExitMode(exitMode::quit);

		this->initTray(trayIconResource);
	}

	void BaseMainWindow::initTray(uint16_t trayIconResource)
	{
		if (!trayIconResource)
		{
			return;
		}

		trayId = GUIFramework::get().generateTrayId();
		trayPopupMenu = CreatePopupMenu();

		tray.cbSize = sizeof(tray);
		tray.hWnd = getHandle();
		tray.uFlags = NIF_MESSAGE | NIF_ICON;
		tray.uCallbackMessage = trayId;
		tray.uVersion = NOTIFYICON_VERSION_4;

		this->setOnClose
		(
			[this]()
			{
				Shell_NotifyIconW(NIM_ADD, &tray);

				Shell_NotifyIconW(NIM_SETVERSION, &tray);

				hide();

				return false;
			}
		);

		this->setOnDestroy
		(
			[this]()
			{
				Shell_NotifyIconW(NIM_DELETE, &tray);

				this->onDestroyEvent();
			}
		);

		LoadIconMetric(GetModuleHandleW(nullptr), MAKEINTRESOURCE(trayIconResource), _LI_METRIC::LIM_LARGE, &tray.hIcon);
	}

	bool BaseMainWindow::addTrayMenuItem(const wstring& text, const function<void()>& onClick)
	{
		return trayPopupMenu ?
			AppendMenuW(trayPopupMenu, MF_STRING, popupMenuItems.emplace_back(GUIFramework::get().generateTrayId(), onClick).first, text.data()) :
			false;
	}

	bool BaseMainWindow::addTrayMenuItem(const wstring& text, const string& functionName, const string& moduleName)
	{
		if (!trayPopupMenu)
		{
			return false;
		}

		AppendMenuW(trayPopupMenu, MF_STRING, popupMenuItems.emplace_back(GUIFramework::get().generateTrayId(), Function(functionName, moduleName)).first, text.data());

		return true;
	}

	bool BaseMainWindow::removeTrayMenuItem(const wstring& text)
	{
		if (!trayPopupMenu)
		{
			return false;
		}

		for (size_t i = 0; i < popupMenuItems.size(); i++)
		{
			MENUITEMINFOW info = {};

			info.cbSize = sizeof(info);
			info.fMask = MIIM_STRING;

			GetMenuItemInfoW(trayPopupMenu, static_cast<uint32_t>(i), true, &info);

			if (info.dwTypeData && info.dwTypeData == text)
			{
				popupMenuItems.erase(popupMenuItems.begin() + i);

				DeleteMenu(trayPopupMenu, static_cast<uint32_t>(i), MF_BYPOSITION);

				return true;
			}
		}

		return false;
	}

	size_t BaseMainWindow::getHash() const
	{
		return typeid(BaseMainWindow).hash_code();
	}

	json::JSONBuilder BaseMainWindow::getStructure() const
	{
		using json::utility::jsonObject;

		json::JSONBuilder builder = BaseSeparateWindow::getStructure();
		jsonObject& current = get<jsonObject>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		if (trayIconResource)
		{
			vector<jsonObject> items;

			current.setInt("trayIconResource", trayIconResource);

			for (size_t i = 0; i < popupMenuItems.size(); i++)
			{
				const Function& function = popupMenuItems[i].second;

				if (function.functionName.size())
				{
					jsonObject object;

					MENUITEMINFOW info = {};

					info.cbSize = sizeof(info);
					info.fMask = MIIM_STRING;

					GetMenuItemInfoW(trayPopupMenu, static_cast<uint32_t>(i), true, &info);

					object.setString("text", info.dwTypeData ? utility::to_string(info.dwTypeData, interfaces::ISerializable::getCodepage()) : "");

					object.setString("functionName"s, function.functionName);

					object.setString("moduleName"s, function.moduleName);

					object.setString("pathToModule"s, GUIFramework::get().getModulesPaths().at(function.moduleName));

					json::utility::appendArray(move(object), items);
				}
			}

			if (items.size())
			{
				current.setArray("items", move(items));
			}
		}

		return builder;
	}

	BaseMainWindow::~BaseMainWindow()
	{
		if (trayPopupMenu)
		{
			DestroyMenu(trayPopupMenu);
		}
	}
}
