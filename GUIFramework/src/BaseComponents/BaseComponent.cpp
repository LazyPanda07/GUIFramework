#include "pch.h"
#include "BaseComponent.h"

#include "BaseComposites/BaseComposite.h"
#include "Exceptions/CantFindSeparateWindowFunctionException.h"
#include "Exceptions/FileDoesNotExist.h"
#include "Interfaces/Components/IResizableComponent.h"

#pragma warning(disable: 6387)

using namespace std;

namespace gui_framework
{
	LRESULT BaseComponent::preWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		isUsed = false;

		return -1;
	}

	BaseComponent::BaseComponent(const wstring& className, const wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent, const string& windowFunctionName, const std::wstring& moduleName) :
		parent(parent),
		className(className),
		windowName(windowName),
		handle(nullptr),
		module(GetModuleHandleW(moduleName.data())),
		desiredWidth(settings.width),
		desiredHeight(settings.height),
		desiredX(settings.x),
		desiredY(settings.y),
		mode(exitMode::destroyWindow),
		largeIcon(nullptr),
		smallIcon(nullptr)
	{
		WNDCLASSEXW classStruct = {};

		if (!GetClassInfoExW(module, className.data(), &classStruct))
		{
			if (windowFunctionName.size())
			{
				WNDPROC windowFunction = reinterpret_cast<WNDPROC>(GetProcAddress(nullptr, (windowFunctionName + "WindowFunction").data()));

				if (!windowFunction)
				{
					throw exceptions::CantFindSeparateWindowFunctionException(windowFunctionName + "WindowFunction");
				}

				classStruct.cbSize = sizeof(WNDCLASSEXW);
				classStruct.lpszClassName = className.data();
				classStruct.hInstance = module;
				classStruct.hCursor = LoadCursorW(module, IDC_ARROW);
				classStruct.lpfnWndProc = windowFunction;
				classStruct.hbrBackground = HBRUSH(COLOR_WINDOW);

				RegisterClassExW(&classStruct);
			}
		}

		handle = CreateWindowExW
		(
			settings.extendedStyles,
			className.data(),
			windowName.data(),
			settings.styles | (parent ? WS_CHILDWINDOW : WS_OVERLAPPEDWINDOW),
			settings.x,
			settings.y,
			settings.width,
			settings.height,
			parent ? parent->handle : nullptr,
			settings.id,
			GetModuleHandleW(nullptr),
			nullptr
		);

		if (!parent)
		{
			SendMessageW(handle, custom_window_messages::initTopLevelWindowPointer, reinterpret_cast<WPARAM>(this), NULL);
		}
		else if (parent->isComposite())
		{
			BaseComposite* composite = static_cast<BaseComposite*>(parent);

			composite->addChild(this);
		}

		ShowWindowAsync(handle, SW_SHOW);
	}

	bool BaseComponent::isComposite() const
	{
		return false;
	}

	LRESULT BaseComponent::windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		if (message == WM_MENUCOMMAND)
		{
			isUsed = true;

			if (mainMenu->getHandle() == reinterpret_cast<HMENU>(lparam))
			{
				mainMenu->handleMessage(static_cast<uint32_t>(wparam));
			}
			else
			{
				popupMenus[reinterpret_cast<HMENU>(lparam)].handleMessage(static_cast<uint32_t>(wparam));
			}

			return 0;
		}

		isUsed = false;

		return -1;
	}

	LRESULT BaseComponent::handleMessages(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		LRESULT result = this->preWindowMessagesHandle(handle, message, wparam, lparam, isUsed);

		if (isUsed)
		{
			return result;
		}

		return this->windowMessagesHandle(handle, message, wparam, lparam, isUsed);
	}

	bool BaseComponent::destroyComponent()
	{
		bool result = DestroyWindow(handle);

		if (result && parent && parent->isComposite())
		{
			DestroyIcon(largeIcon);
			DestroyIcon(smallIcon);

			BaseComposite* parentComposite = static_cast<BaseComposite*>(parent);

			parentComposite->removeChild(this);
		}

		return result;
	}

	bool BaseComponent::asyncDestroyComponent()
	{
		bool result = PostMessageW(handle, WM_CLOSE, NULL, NULL);

		if (result && parent && parent->isComposite())
		{
			DestroyIcon(largeIcon);
			DestroyIcon(smallIcon);

			BaseComposite* parentComposite = static_cast<BaseComposite*>(parent);

			parentComposite->removeChild(this);
		}

		return result;
	}

	unique_ptr<Menu>& BaseComponent::createMainMenu(const wstring& menuName)
	{
		popupMenus.clear();

		mainMenu = make_unique<Menu>(menuName, handle);

		return mainMenu;
	}

	Menu& BaseComponent::addPopupMenu(const wstring& menuName)
	{
		Menu menu(menuName, nullptr);

		auto it = popupMenus.emplace(menu.getHandle(), move(menu)).first;

		return popupMenus.at(it->first);
	}

	void BaseComponent::removePopupMenus(const wstring& menuName)
	{
		vector<HMENU> itemsToRemove;

		for (const auto& [handle, popupMenu] : popupMenus)
		{
			if (popupMenu.getName() == menuName)
			{
				itemsToRemove.push_back(handle);
			}
		}

		for (const auto& i : itemsToRemove)
		{
			popupMenus.erase(i);
		}
	}

	void BaseComponent::changeBackgroundColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		SendMessageW(handle, WM_ERASEBKGND, reinterpret_cast<WPARAM>(CreateSolidBrush(RGB(red, green, blue))), NULL);
	}

	void BaseComponent::setDesiredWidth(uint16_t desiredWidth)
	{
		this->desiredWidth = desiredWidth;
	}

	void BaseComponent::setDesiredHeight(uint16_t desiredHeight)
	{
		this->desiredHeight = desiredHeight;
	}

	void BaseComponent::setDesiredX(int desiredX)
	{
		this->desiredX = desiredX;
	}

	void BaseComponent::setDesiredY(int desiredY)
	{
		this->desiredY = desiredY;
	}

	void BaseComponent::setExitMode(exitMode mode)
	{
		this->mode = mode;
	}

	void BaseComponent::setLargeIcon(const filesystem::path& pathToLargeIcon)
	{
		if (!filesystem::exists(pathToLargeIcon))
		{
			throw exceptions::FileDoesNotExist(pathToLargeIcon);
		}

		if (largeIcon)
		{
			DestroyIcon(largeIcon);

			largeIcon = nullptr;
		}

		largeIcon = static_cast<HICON>(LoadImageW(nullptr, pathToLargeIcon.wstring().data(), IMAGE_ICON, standard_sizes::largeIconWidth, standard_sizes::largeIconHeight, LR_LOADFROMFILE));

		SendMessageW(handle, WM_SETICON, ICON_BIG, reinterpret_cast<LPARAM>(largeIcon));
	}

	void BaseComponent::setSmallIcon(const filesystem::path& pathToLargeIcon)
	{
		if (!filesystem::exists(pathToLargeIcon))
		{
			throw exceptions::FileDoesNotExist(pathToLargeIcon);
		}

		if (largeIcon)
		{
			DestroyIcon(largeIcon);

			smallIcon = nullptr;
		}

		smallIcon = static_cast<HICON>(LoadImageW(nullptr, pathToLargeIcon.wstring().data(), IMAGE_ICON, standard_sizes::largeIconWidth, standard_sizes::largeIconHeight, LR_LOADFROMFILE));

		SendMessageW(handle, WM_SETICON, ICON_SMALL, reinterpret_cast<LPARAM>(smallIcon));
	}

	BaseComponent* BaseComponent::getParent() const
	{
		return parent;
	}

	HWND BaseComponent::getHandle() const
	{
		return handle;
	}

	const wstring& BaseComponent::getWindowName() const
	{
		return windowName;
	}

	const wstring& BaseComponent::getClassName() const
	{
		return className;
	}

	uint16_t BaseComponent::getDesiredWidth() const
	{
		return desiredWidth;
	}

	uint16_t BaseComponent::getDesiredHeight() const
	{
		return desiredHeight;
	}

	uint16_t BaseComponent::getActualWidth() const
	{
		RECT sizes;

		GetClientRect(handle, &sizes);

		return static_cast<uint16_t>(sizes.right - sizes.left);
	}

	uint16_t BaseComponent::getActualHeight() const
	{
		RECT sizes;

		GetClientRect(handle, &sizes);

		return static_cast<uint16_t>(sizes.bottom - sizes.top);
	}

	RECT BaseComponent::getActualCoordinates() const
	{
		RECT coordinates;

		GetWindowRect(handle, &coordinates);

		MapWindowPoints(HWND_DESKTOP, parent ? parent->getHandle() : HWND_DESKTOP, reinterpret_cast<POINT*>(&coordinates), 2);

		return coordinates;
	}

	int BaseComponent::getDesiredX() const
	{
		return desiredX;
	}

	int BaseComponent::getDesiredY() const
	{
		return desiredY;
	}

	BaseComponent::exitMode BaseComponent::getExitMode() const
	{
		return mode;
	}

	const unique_ptr<Menu>& BaseComponent::getMainMenu() const
	{
		return mainMenu;
	}

	unique_ptr<Menu>& BaseComponent::getMainMenu()
	{
		return mainMenu;
	}

	vector<const Menu*> BaseComponent::getPopupMenus() const
	{
		vector<const Menu*> result;

		result.reserve(popupMenus.size());

		for (const auto& [_, popupMenu] : popupMenus)
		{
			result.push_back(&popupMenu);
		}

		return result;
	}

	BaseComponent::~BaseComponent()
	{
		if (!this->destroyComponent())
		{
			this->asyncDestroyComponent();
		}
	}
}
