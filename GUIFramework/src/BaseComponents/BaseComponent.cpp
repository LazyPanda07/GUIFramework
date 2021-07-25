#include "pch.h"
#include "BaseComponent.h"

#include "BaseComposites/BaseComposite.h"
#include "Exceptions/CantFindCompositeFunctionException.h"
#include "Exceptions/FileDoesNotExist.h"
#include "Interfaces/Components/IResizableComponent.h"

#pragma warning(disable: 6387)
#pragma warning(disable: 4312)

using namespace std;

namespace gui_framework
{
	void BaseComponent::runFunctionAsync(const function<void()>& callable, const function<void()>& callback) noexcept
	{
		GUIFramework::get().addTask(callable, callback);
	}

	void BaseComponent::runFunctionAsync(function<void()>&& callable, const function<void()>& callback) noexcept
	{
		GUIFramework::get().addTask(move(callable), callback);
	}

	LRESULT BaseComponent::preWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		isUsed = false;

		if (message == WM_SIZE)
		{
			interfaces::IResizableComponent* resizableComponent = dynamic_cast<interfaces::IResizableComponent*>(this);

			if (resizableComponent && !resizableComponent->getBlockResize())
			{
				isUsed = true;

				resizableComponent->resize(LOWORD(lparam), HIWORD(lparam));

				return 0;
			}
		}

		return -1;
	}

	BaseComponent::BaseComponent(const wstring& className, const wstring& windowName, const utility::ComponentSettings& settings, const interfaces::IStyles& styles, BaseComponent* parent, const string& windowFunctionName, const std::wstring& moduleName) :
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
		smallIcon(nullptr),
		id(parent ? GUIFramework::get().generateId(windowName) : NULL),
		backgroundColor(RGB(255, 255, 255)),
		textColor(RGB(0, 0, 0))
	{
		WNDCLASSEXW classStruct = {};

		if (!GetClassInfoExW(module, className.data(), &classStruct))
		{
			if (windowFunctionName.size())
			{
				WNDPROC windowFunction = reinterpret_cast<WNDPROC>(GetProcAddress(nullptr, (windowFunctionName + "WindowFunction").data()));

				if (!windowFunction)
				{
					throw exceptions::CantFindCompositeFunctionException(windowFunctionName + "WindowFunction");
				}

				classStruct.cbSize = sizeof(WNDCLASSEXW);
				classStruct.lpszClassName = className.data();
				classStruct.hInstance = module;
				classStruct.hCursor = LoadCursorW(module, IDC_ARROW);
				classStruct.lpfnWndProc = windowFunction;
				classStruct.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW);

				RegisterClassExW(&classStruct);
			}
		}

		handle = CreateWindowExW
		(
			static_cast<DWORD>(styles.getExtendedStyles()),
			classStruct.lpszClassName,
			windowName.data(),
			static_cast<DWORD>(styles.getStyles()) | (parent ? WS_CHILDWINDOW | WS_BORDER : WS_OVERLAPPEDWINDOW),
			settings.x,
			settings.y,
			settings.width,
			settings.height,
			parent ? parent->getHandle() : nullptr,
			reinterpret_cast<HMENU>(id),
			module,
			nullptr
		);

		if (!parent)
		{
			SendMessageW(handle, custom_window_messages::initTopLevelWindowPointer, reinterpret_cast<WPARAM>(this), NULL);
		}
		else if (parent->isComposite())
		{
			BaseComposite* composite = static_cast<BaseComposite*>(parent);
			BaseComponent* topLevelWindow = parent;

			composite->addChild(this);

			while (topLevelWindow->getParent())
			{
				topLevelWindow = topLevelWindow->getParent();
			}

			SendMessageW(handle, custom_window_messages::initTopLevelWindowPointer, reinterpret_cast<WPARAM>(topLevelWindow), NULL);
		}

		ShowWindow(handle, SW_SHOW);
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

		this->pathToLargeIcon = pathToLargeIcon.string();

		if (largeIcon)
		{
			DestroyIcon(largeIcon);

			largeIcon = nullptr;
		}

		largeIcon = static_cast<HICON>(LoadImageW(nullptr, pathToLargeIcon.wstring().data(), IMAGE_ICON, standard_sizes::largeIconWidth, standard_sizes::largeIconHeight, LR_LOADFROMFILE));

		SendMessageW(handle, WM_SETICON, ICON_BIG, reinterpret_cast<LPARAM>(largeIcon));
	}

	void BaseComponent::setSmallIcon(const filesystem::path& pathToSmallIcon)
	{
		if (!filesystem::exists(pathToSmallIcon))
		{
			throw exceptions::FileDoesNotExist(pathToSmallIcon);
		}

		this->pathToSmallIcon = pathToSmallIcon.string();

		if (smallIcon)
		{
			DestroyIcon(smallIcon);

			smallIcon = nullptr;
		}

		smallIcon = static_cast<HICON>(LoadImageW(nullptr, pathToSmallIcon.wstring().data(), IMAGE_ICON, standard_sizes::smallIconWidth, standard_sizes::smallIconHeight, LR_LOADFROMFILE));

		SendMessageW(handle, WM_SETICON, ICON_SMALL, reinterpret_cast<LPARAM>(smallIcon));
	}

	void BaseComponent::setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		backgroundColor = RGB(red, green, blue);

		InvalidateRect(handle, nullptr, true);
	}

	void BaseComponent::setTextColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		textColor = RGB(red, green, blue);

		InvalidateRect(handle, nullptr, true);
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

	uint32_t BaseComponent::getId() const
	{
		return id;
	}

	COLORREF BaseComponent::getBackgroundColor() const
	{
		return backgroundColor;
	}

	COLORREF BaseComponent::getTextColor() const
	{
		return textColor;
	}

	json::JSONBuilder BaseComponent::getStructure(json::JSONBuilder* parentStructure) const
	{
		using json::utility::objectSmartPointer;
		using json::utility::jsonObject;
		using json::utility::appendArray;

		uint32_t codepage = ISerializable::getCodepage();
		json::JSONBuilder builder(codepage);

		objectSmartPointer<jsonObject> structure = json::utility::make_object<jsonObject>();
		vector<objectSmartPointer<jsonObject>> backgroundColorJSON;
		vector<objectSmartPointer<jsonObject>> textColorJSON;

		appendArray(static_cast<int64_t>(GetRValue(backgroundColor)), backgroundColorJSON);
		appendArray(static_cast<int64_t>(GetGValue(backgroundColor)), backgroundColorJSON);
		appendArray(static_cast<int64_t>(GetBValue(backgroundColor)), backgroundColorJSON);

		appendArray(static_cast<int64_t>(GetRValue(textColor)), textColorJSON);
		appendArray(static_cast<int64_t>(GetGValue(textColor)), textColorJSON);
		appendArray(static_cast<int64_t>(GetBValue(textColor)), textColorJSON);

		structure->data.push_back({ "className"s, utility::to_string(className, codepage) });

		structure->data.push_back({ "desiredX"s, desiredX });
		structure->data.push_back({ "desiredY"s, desiredY });

		structure->data.push_back({ "desiredWidth"s, static_cast<uint64_t>(desiredWidth) });
		structure->data.push_back({ "desiredHeight"s, static_cast<uint64_t>(desiredHeight) });

		structure->data.push_back({ "backgroundColor"s, move(backgroundColorJSON) });
		structure->data.push_back({ "textColor"s, move(textColorJSON) });

		if (pathToSmallIcon.size())
		{
			structure->data.push_back({ "pathToSmallIcon"s, pathToSmallIcon });
		}

		if (pathToLargeIcon.size())
		{
			structure->data.push_back({ "pathToLargeIcon"s, pathToLargeIcon });
		}

		structure->data.push_back({ "exitMode"s, static_cast<int64_t>(mode) });

		// TODO: serialize menus
		if (false && mainMenu)
		{
			smartPointerType<json::JSONBuilder::objectType> menuStructure(new json::JSONBuilder::objectType());

			menuStructure->data.push_back({ "mainMenuName"s, utility::to_string(mainMenu->getName(), codepage) });

			for (const auto& [menuHandle, menu] : popupMenus)
			{

			}

			structure->data.push_back({ "menuStructure"s, move(menuStructure) });
		}

		builder.push_back(make_pair(utility::to_string(windowName, codepage), move(structure)));

		return builder;
	}

	BaseComponent::~BaseComponent()
	{
		if (!this->destroyComponent())
		{
			this->asyncDestroyComponent();
		}

		try
		{
			GUIFramework::get().removeId(windowName, id);
		}
		catch (const exception&)
		{

		}
	}
}
