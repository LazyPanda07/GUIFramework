#include "BaseMainWindow.h"

#include <windowsx.h>

#include "GUIFramework.h"

using namespace std;

namespace gui_framework
{
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

			if (auto it = ranges::find_if(popupMenuItems, [id](const pair<uint32_t, function<void()>>& item) { return item.first == id; }); it != popupMenuItems.end())
			{
				isUsed = true;

				it->second();
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
		clicks(0)
	{
		// TODO: serialization/deserialization
		// TODO: localization

		this->setExitMode(exitMode::quit);

		if (trayIconResource)
		{
			tray.cbSize = sizeof(tray);
			tray.hWnd = getHandle();
			tray.uFlags = NIF_MESSAGE | NIF_ICON;
			tray.uCallbackMessage = trayId;
			tray.uVersion = NOTIFYICON_VERSION_4;

			trayId = GUIFramework::get().generateTrayId();
			trayPopupMenu = CreatePopupMenu();

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
				}
			);

			LoadIconMetric(GetModuleHandleW(nullptr), MAKEINTRESOURCE(trayIconResource), _LI_METRIC::LIM_LARGE, &tray.hIcon);
		}
	}

	bool BaseMainWindow::addTrayMenuItem(const wstring& text, const function<void()>& onClick)
	{
		return trayPopupMenu ?
			AppendMenuW(trayPopupMenu, MF_STRING, popupMenuItems.emplace_back(GUIFramework::get().generateTrayId(), onClick).first, text.data()) :
			false;
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

	BaseMainWindow::~BaseMainWindow()
	{
		if (trayPopupMenu)
		{
			DestroyMenu(trayPopupMenu);
		}
	}
}
