#include "BaseComponent.h"

#include "BaseComposites/BaseComposite.h"
#include "GUIFramework.h"
#include "Interfaces/Components/IResizableComponent.h"
#include "Interfaces/Components/ITextOperations.h"
#include "Interfaces/Localization/IMultipleTextLocalized.h"
#include "Interfaces/Localization/ISingleTextLocalized.h"

#include "Exceptions/CantFindCompositeFunctionException.h"
#include "Exceptions/FileDoesNotExist.h"

#pragma warning(disable: 6387)
#pragma warning(disable: 4312)

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

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

	LRESULT BaseComponent::windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		isUsed = false;

		return -1;
	}

	void BaseComponent::setLocalizationKeys(interfaces::ITextLocalized* localized, const vector<string>& localizationKeys)
	{
		if (interfaces::ISingleTextLocalized* single = dynamic_cast<interfaces::ISingleTextLocalized*>(localized); single && localizationKeys.size())
		{
			single->setLocalizationKey(localizationKeys.front());
		}
		else if (interfaces::IMultipleTextLocalized* multi = dynamic_cast<interfaces::IMultipleTextLocalized*>(localized))
		{
			for (string_view localizationKey : localizationKeys)
			{
				multi->addLocalizationKey(localizationKey);
			}
		}
	}

	BaseComponent::BaseComponent(wstring_view className, wstring_view windowName, const utility::ComponentSettings& settings, const interfaces::IStyles& styles, BaseComposite* parent, string_view windowFunctionName, string_view moduleName, uint16_t smallIconResource, uint16_t largeIconResources) :
		parent(parent),
		className(className),
		windowName(windowName),
		handle(nullptr),
		desiredWidth(settings.width),
		desiredHeight(settings.height),
		desiredX(settings.x),
		desiredY(settings.y),
		id(parent ? GUIFramework::get().generateId(windowName) : NULL),
		backgroundColor(RGB(255, 255, 255)),
		textColor(RGB(0, 0, 0))
	{
		WNDCLASSEXW classStruct = {};
		interfaces::ITextLocalized* localized = dynamic_cast<interfaces::ITextLocalized*>(this);
		const unordered_map<string, HMODULE, localization::utility::StringViewHash, localization::utility::StringViewEqual>& modules = GUIFramework::get().getModules();
		const HMODULE* findedModule = nullptr;

		for (const auto& [moduleName, module] : modules)
		{
			if (GetClassInfoExW(module, className.data(), &classStruct))
			{
				findedModule = &module;

				break;
			}
		}

		if (!findedModule)
		{
			if (windowFunctionName.size())
			{
				WNDPROC windowFunction = reinterpret_cast<WNDPROC>(GetProcAddress(nullptr, format("{}WindowFunction", windowFunctionName).data()));

				if (!windowFunction)
				{
					throw exceptions::CantFindCompositeFunctionException(format("{}WindowFunction", windowFunctionName), __FILE__, __FUNCTION__, __LINE__);
				}

				classStruct.cbSize = sizeof(WNDCLASSEXW);
				classStruct.lpszClassName = className.data();
				classStruct.hInstance = utility::getCurrentModule();
				classStruct.hCursor = LoadCursorW(nullptr, IDC_ARROW);
				classStruct.lpfnWndProc = windowFunction;
				classStruct.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW);

				if (smallIconResource)
				{
					if (moduleName.size())
					{
						if (auto it = modules.find(moduleName); it != modules.end())
						{
							classStruct.hIconSm = static_cast<HICON>(LoadImageW(it->second, MAKEINTRESOURCEW(largeIconResources), IMAGE_ICON, standard_sizes::smallIconWidth, standard_sizes::smallIconHeight, NULL));
						}
						else
						{
							throw runtime_error(format("Can't load small icon resource for {}", moduleName));
						}
					}
					else
					{
						classStruct.hIconSm = static_cast<HICON>(LoadImageW(classStruct.hInstance, MAKEINTRESOURCEW(largeIconResources), IMAGE_ICON, standard_sizes::smallIconWidth, standard_sizes::smallIconHeight, NULL));
					}
				}

				if (largeIconResources)
				{
					if (moduleName.size())
					{
						if (auto it = modules.find(moduleName); it != modules.end())
						{
							classStruct.hIcon = static_cast<HICON>(LoadImageW(it->second, MAKEINTRESOURCEW(largeIconResources), IMAGE_ICON, standard_sizes::largeIconWidth, standard_sizes::largeIconHeight, NULL));
						}
						else
						{
							throw runtime_error(format("Can't load large icon resource for {}", moduleName));
						}
					}
					else
					{
						classStruct.hIcon = static_cast<HICON>(LoadImageW(classStruct.hInstance, MAKEINTRESOURCEW(largeIconResources), IMAGE_ICON, standard_sizes::largeIconWidth, standard_sizes::largeIconHeight, NULL));
					}
				}

				RegisterClassExW(&classStruct);
			}
		}

		handle = CreateWindowExW
		(
			static_cast<DWORD>(styles.getExtendedStyles() | settings.styles.getExtendedStyles()),
			classStruct.lpszClassName,
			windowName.data(),
			static_cast<DWORD>(styles.getStyles()) | static_cast<DWORD>(settings.styles.getStyles()) | (parent ? WS_CHILDWINDOW | WS_BORDER : WS_OVERLAPPEDWINDOW),
			settings.x,
			settings.y,
			settings.width,
			settings.height,
			parent ? parent->getHandle() : nullptr,
			reinterpret_cast<HMENU>(id),
			findedModule ? *findedModule : utility::getCurrentModule(),
			nullptr
		);

		GUIFramework::get().addComponent(this);

		this->styles = utility::make_smart_pointer<interfaces::IStyles>(styles);

		if (!parent)
		{
			SendMessageW(handle, custom_window_messages::initTopLevelWindowPointer, reinterpret_cast<WPARAM>(this), NULL);
		}
		else
		{
			BaseComponent* topLevelWindow = parent;

			parent->addChild(this);

			while (topLevelWindow->getParent())
			{
				topLevelWindow = topLevelWindow->getParent();
			}

			SendMessageW(handle, custom_window_messages::initTopLevelWindowPointer, reinterpret_cast<WPARAM>(topLevelWindow), NULL);
		}

		ShowWindow(handle, SW_SHOW);

		if (localized)
		{
			this->setLocalizationKeys(localized, settings.localizationKeys);

			localized->updateLocalizationEvent();
		}
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

		if (result && parent)
		{
			if (BaseComposite* parentComposite = dynamic_cast<BaseComposite*>(parent))
			{
				parentComposite->removeChild(this);
			}
		}

		return result;
	}

	bool BaseComponent::asyncDestroyComponent()
	{
		bool result = PostMessageW(handle, WM_CLOSE, NULL, NULL);

		if (result && parent)
		{
			if (BaseComposite* parentComposite = dynamic_cast<BaseComposite*>(parent))
			{
				parentComposite->removeChild(this);
			}
		}

		return result;
	}

	void BaseComponent::enable()
	{
		EnableWindow(handle, true);
	}

	void BaseComponent::disable()
	{
		EnableWindow(handle, false);
	}

	bool BaseComponent::isEnabled() const
	{
		return IsWindowEnabled(handle);
	}

	bool BaseComponent::isDisabled() const
	{
		return !this->isEnabled();
	}

	LRESULT BaseComponent::sendRawMessage(UINT message, WPARAM wparam, LPARAM lparam)
	{
		return SendMessageW(handle, message, wparam, lparam);
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

	wstring_view BaseComponent::getWindowName() const
	{
		return windowName;
	}

	wstring_view BaseComponent::getClassName() const
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

	const smartPointerType<interfaces::IStyles>& BaseComponent::getStyles() const
	{
		return styles;
	}

	json::JSONBuilder BaseComponent::getStructure() const
	{
		using json::utility::jsonObject;
		using json::utility::appendArray;

		uint32_t codepage = ISerializable::getCodepage();
		json::JSONBuilder builder(codepage);

		jsonObject structure;
		vector<jsonObject> backgroundColorJSON;
		vector<jsonObject> textColorJSON;
		vector<jsonObject> localizationKeys;
		const interfaces::ITextOperations* textOperations = dynamic_cast<const interfaces::ITextOperations*>(this);

		appendArray(static_cast<int64_t>(GetRValue(backgroundColor)), backgroundColorJSON);
		appendArray(static_cast<int64_t>(GetGValue(backgroundColor)), backgroundColorJSON);
		appendArray(static_cast<int64_t>(GetBValue(backgroundColor)), backgroundColorJSON);

		appendArray(static_cast<int64_t>(GetRValue(textColor)), textColorJSON);
		appendArray(static_cast<int64_t>(GetGValue(textColor)), textColorJSON);
		appendArray(static_cast<int64_t>(GetBValue(textColor)), textColorJSON);

		structure.data.push_back({ "className"s, utility::to_string(className, codepage) });

		structure.data.push_back({ "hash"s, this->getHash() });

		structure.data.push_back({ "desiredX"s, desiredX });
		structure.data.push_back({ "desiredY"s, desiredY });

		structure.data.push_back({ "desiredWidth"s, static_cast<uint64_t>(desiredWidth) });
		structure.data.push_back({ "desiredHeight"s, static_cast<uint64_t>(desiredHeight) });

		structure.data.push_back({ "backgroundColor"s, move(backgroundColorJSON) });
		structure.data.push_back({ "textColor"s, move(textColorJSON) });

		if (textOperations)
		{
			structure.data.push_back({ "text"s, utility::to_string(textOperations->getText(), codepage) });
		}

		structure.data.push_back({ "styles"s, styles->getStyles() });

		structure.data.push_back({ "extendedStyles"s, styles->getExtendedStyles() });

		if (const interfaces::ISingleTextLocalized* single = dynamic_cast<const interfaces::ISingleTextLocalized*>(this))
		{
			appendArray(single->getLocalizationKey(), localizationKeys);
		}
		else if (const interfaces::IMultipleTextLocalized* multiple = dynamic_cast<const interfaces::IMultipleTextLocalized*>(this))
		{
			for (const string& localizationKey : multiple->getLocalizationKeys())
			{
				appendArray(localizationKey, localizationKeys);
			}
		}

		if (localizationKeys.size())
		{
			structure.data.push_back({ "localizationKeys"s, move(localizationKeys) });
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

		GUIFramework::get().removeComponent(this);
	}
}
