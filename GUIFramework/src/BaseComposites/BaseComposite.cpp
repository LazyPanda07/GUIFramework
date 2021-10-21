#include "headers.h"
#include "BaseComposite.h"

#include "Interfaces/Components/IResizableComponent.h"

#include "Exceptions/FileDoesNotExist.h"

using namespace std;

namespace gui_framework
{
	LRESULT BaseComposite::preWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		isUsed = false;

		if (message == WM_SIZE)
		{
			BaseComponent* component = GUIFramework::get().findComponent(handle);

			if (component && component->isComposite())
			{
				interfaces::IResizableComponent* resizableComposite = dynamic_cast<interfaces::IResizableComponent*>(component);

				if (resizableComposite && !resizableComposite->getBlockResize())
				{
					isUsed = true;

					const vector<unique_ptr<BaseComponent>>& childrenToResize = static_cast<BaseComposite*>(component)->getChildren();
					uint16_t width = LOWORD(lparam);
					uint16_t height = HIWORD(lparam);

					for (const auto& i : childrenToResize)
					{
						interfaces::IResizableComponent* resizable = dynamic_cast<interfaces::IResizableComponent*>(i.get());

						if (resizable)
						{
							resizable->resize(width, height);
						}
					}

					return 0;
				}
			}
		}

		return -1;
	}

	LRESULT BaseComposite::compositeWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		if (message >= WM_CTLCOLOREDIT && message <= WM_CTLCOLORSTATIC)
		{
			BaseComponent* component = this->findChild(reinterpret_cast<HWND>(lparam));

			if (component)
			{
				isUsed = true;

				SetBkColor(reinterpret_cast<HDC>(wparam), component->getBackgroundColor());

				SetTextColor(reinterpret_cast<HDC>(wparam), component->getTextColor());

				return reinterpret_cast<LRESULT>(CreateSolidBrush(component->getBackgroundColor()));
			}
		}
		else if (message == WM_MENUCOMMAND)
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

	LRESULT BaseComposite::windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		LRESULT result = this->compositeWindowMessagesHandle(handle, message, wparam, lparam, isUsed);

		if (isUsed)
		{
			return result;
		}

		result = BaseComponent::windowMessagesHandle(handle, message, wparam, lparam, isUsed);

		if (isUsed)
		{
			return result;
		}

		for (const auto& i : children)
		{
			if (!i)
			{
				continue;
			}

			result = i->windowMessagesHandle(handle, message, wparam, lparam, isUsed);

			if (isUsed)
			{
				return result;
			}
		}

		isUsed = false;

		return -1;
	}

	vector<pair<string, json::utility::objectSmartPointer<json::utility::jsonObject>>> BaseComposite::getChildrenStructure() const
	{
		vector<json::JSONBuilder> childrenStructure;
		vector<pair<string, json::utility::objectSmartPointer<json::utility::jsonObject>>> data;

		childrenStructure.reserve(children.size());

		ranges::for_each(children, [&childrenStructure](const unique_ptr<BaseComponent>& child) { childrenStructure.push_back(child->getStructure()); });

		for (size_t i = 0; i < children.size(); i++)
		{
			string childWindowName = utility::to_string(children[i]->getWindowName(), children[i]->getCodepage());

			auto& childStructure = get<json::utility::objectSmartPointer<json::utility::jsonObject>>(childrenStructure[i][childWindowName]);

			data.push_back({ move(childWindowName), move(childStructure) });
		}

		return data;
	}

	void BaseComposite::addChild(BaseComponent* child)
	{
		children.push_back(unique_ptr<BaseComponent>(child));
	}

	BaseComposite::BaseComposite(const wstring& className, const wstring& windowName, const utility::ComponentSettings& settings, const interfaces::IStyles& styles, BaseComponent* parent, const string& windowFunctionName, const string& moduleName, uint16_t smallIconResource, uint16_t largeIconResource) :
		BaseComponent
		(
			className,
			windowName,
			settings,
			styles,
			parent,
			windowFunctionName,
			moduleName,
			smallIconResource,
			largeIconResource
		),
		windowFunctionName(windowFunctionName),
		mode(exitMode::destroyWindow),
		largeIcon(nullptr),
		smallIcon(nullptr)
	{

	}

	void BaseComposite::removeChild(BaseComponent* child)
	{
		for (auto it = children.begin(); it != children.end(); it++)
		{
			if (it->get() == child)
			{
				it->reset();

				children.erase(it);

				break;
			}
		}
	}

	void BaseComposite::removeComponents(const wstring& componentName)
	{
		erase_if(children, [&componentName](const unique_ptr<BaseComponent>& child) { return child->getWindowName() == componentName; });
	}

	BaseComponent* BaseComposite::findChild(const wstring& windowName) const
	{
		BaseComponent* result = nullptr;

		for (const auto& i : children)
		{
			if (i->getWindowName() == windowName)
			{
				result = i.get();

				break;
			}
			else if (i->isComposite())
			{
				result = static_cast<BaseComposite*>(i.get())->findChild(windowName);

				if (result)
				{
					break;
				}
			}
		}

		return result;
	}

	BaseComponent* BaseComposite::findChild(HWND handle) const
	{
		BaseComponent* result = nullptr;

		for (const auto& i : children)
		{
			if (i->getHandle() == handle)
			{
				result = i.get();

				break;
			}
			else if (i->isComposite())
			{
				result = static_cast<BaseComposite*>(i.get())->findChild(handle);

				if (result)
				{
					break;
				}
			}
		}

		return result;
	}

	vector<BaseComponent*> BaseComposite::findChildren(const wstring& windowName) const
	{
		vector<BaseComponent*> result;

		for (const auto& i : children)
		{
			if (i->getWindowName() == windowName)
			{
				result.push_back(i.get());
			}
			else if (i->isComposite())
			{
				vector<BaseComponent*> subChildren = static_cast<BaseComposite*>(i.get())->findChildren(windowName);

				copy(subChildren.begin(), subChildren.end(), back_inserter(result));
			}
		}

		return result;
	}

	unique_ptr<Menu>& BaseComposite::createMainMenu(const wstring& menuName)
	{
		popupMenus.clear();

		mainMenu = make_unique<Menu>(menuName, handle);

		return mainMenu;
	}

	Menu& BaseComposite::addPopupMenu(const wstring& menuName)
	{
		Menu menu(menuName, nullptr);

		auto it = popupMenus.emplace(menu.getHandle(), move(menu)).first;

		return popupMenus.at(it->first);
	}

	void BaseComposite::removePopupMenus(const wstring& menuName)
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

	bool BaseComposite::isComposite() const
	{
		return true;
	}

	void BaseComposite::setExitMode(exitMode mode)
	{
		this->mode = mode;
	}

	BaseComposite::exitMode BaseComposite::getExitMode() const
	{
		return mode;
	}

	const vector<unique_ptr<BaseComponent>>& BaseComposite::getChildren() const
	{
		return children;
	}

	const unique_ptr<Menu>& BaseComposite::getMainMenu() const
	{
		return mainMenu;
	}

	unique_ptr<Menu>& BaseComposite::getMainMenu()
	{
		return mainMenu;
	}

	vector<const Menu*> BaseComposite::getPopupMenus() const
	{
		vector<const Menu*> result;

		result.reserve(popupMenus.size());

		for (const auto& [_, popupMenu] : popupMenus)
		{
			result.push_back(&popupMenu);
		}

		return result;
	}

	void BaseComposite::setLargeIcon(const filesystem::path& pathToLargeIcon)
	{
		if (!filesystem::exists(pathToLargeIcon))
		{
			throw exceptions::FileDoesNotExist(pathToLargeIcon);
		}

		this->pathToLargeIcon = pathToLargeIcon;

		if (largeIcon)
		{
			DestroyIcon(largeIcon);

			largeIcon = nullptr;
		}

		largeIcon = static_cast<HICON>(LoadImageW(nullptr, pathToLargeIcon.wstring().data(), IMAGE_ICON, standard_sizes::largeIconWidth, standard_sizes::largeIconHeight, LR_LOADFROMFILE));

		SendMessageW(handle, WM_SETICON, ICON_BIG, reinterpret_cast<LPARAM>(largeIcon));
	}

	void BaseComposite::setSmallIcon(const filesystem::path& pathToSmallIcon)
	{
		if (!filesystem::exists(pathToSmallIcon))
		{
			throw exceptions::FileDoesNotExist(pathToSmallIcon);
		}

		this->pathToSmallIcon = pathToSmallIcon;

		if (smallIcon)
		{
			DestroyIcon(smallIcon);

			smallIcon = nullptr;
		}

		smallIcon = static_cast<HICON>(LoadImageW(nullptr, pathToSmallIcon.wstring().data(), IMAGE_ICON, standard_sizes::smallIconWidth, standard_sizes::smallIconHeight, LR_LOADFROMFILE));

		SendMessageW(handle, WM_SETICON, ICON_SMALL, reinterpret_cast<LPARAM>(smallIcon));
	}

	iterators::composite_forward_iterator BaseComposite::begin() noexcept
	{
		return iterators::composite_forward_iterator(this);
	}

	iterators::composite_const_forward_iterator BaseComposite::cbegin() const noexcept
	{
		return iterators::composite_const_forward_iterator(static_cast<BaseComponent*>(const_cast<BaseComposite*>(this)));
	}

	iterators::composite_forward_iterator BaseComposite::end() noexcept
	{
		return iterators::composite_forward_iterator(nullptr);
	}

	iterators::composite_const_forward_iterator BaseComposite::cend() const noexcept
	{
		return iterators::composite_const_forward_iterator(nullptr);
	}

	void BaseComposite::setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		BaseComponent::setBackgroundColor(red, green, blue);

		SetClassLongPtrW(handle, GCLP_HBRBACKGROUND, reinterpret_cast<LONG_PTR>(CreateSolidBrush(backgroundColor)));

		InvalidateRect(handle, nullptr, true);
	}

	json::JSONBuilder BaseComposite::getStructure() const
	{
		using json::utility::jsonObject;
		using json::utility::objectSmartPointer;

		json::JSONBuilder builder = BaseComponent::getStructure();
		vector<pair<string, objectSmartPointer<jsonObject>>> data = this->getChildrenStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);
		GUIFramework& instance = GUIFramework::get();

		current->data.push_back({ "windowFunctionName"s, windowFunctionName });

		current->data.push_back({ "exitMode"s, static_cast<int64_t>(mode) });

		if (!pathToSmallIcon.empty())
		{
			current->data.push_back({ "pathToSmallIcon"s, utility::getStringFromRawPath(pathToSmallIcon) });
		}

		if (!pathToLargeIcon.empty())
		{
			current->data.push_back({ "pathToLargeIcon"s, utility::getStringFromRawPath(pathToLargeIcon) });
		}

		if (mainMenu)
		{
			objectSmartPointer<jsonObject> menuStructure = json::utility::make_object<jsonObject>();
			json::JSONBuilder mainMenuBuilder = mainMenu->getStructure();
			vector<objectSmartPointer<jsonObject>> popupItems;

			menuStructure->data.push_back({ "mainMenuName"s, get<string>(mainMenuBuilder["menuName"]) });

			menuStructure->data.push_back({ "mainMenuItems"s, move(mainMenuBuilder["items"]) });

			for (const auto& [menuHandle, menu] : popupMenus)
			{
				objectSmartPointer<jsonObject> tem = json::utility::make_object<jsonObject>();
				json::JSONBuilder temBuilder = menu.getStructure();

				tem->data.push_back({ "menuName"s, get<string>(temBuilder["menuName"]) });
				tem->data.push_back({ "menuId"s, get<uint64_t>(temBuilder["menuId"]) });
				tem->data.push_back({ "items"s, move(temBuilder["items"]) });

				json::utility::appendArray(move(tem), popupItems);
			}

			menuStructure->data.push_back({ "popupItems"s, move(popupItems) });

			current->data.push_back(make_pair("menuStructure"s, move(menuStructure)));
		}

		if (data.size())
		{
			vector<objectSmartPointer<jsonObject>>& childrenStructures = get<vector<objectSmartPointer<jsonObject>>>(current->data.emplace_back(make_pair("children"s, vector<objectSmartPointer<jsonObject>>())).second);

			for (auto& i : data)
			{
				objectSmartPointer<jsonObject> topLevel = json::utility::make_object<jsonObject>();
				objectSmartPointer<jsonObject> tem = json::utility::make_object<jsonObject>();

				tem->data.push_back(move(i));

				topLevel->data.push_back({ ""s, move(tem) });

				childrenStructures.push_back(move(topLevel));
			}
		}

		if (!current->contains("hotkeys", json::utility::variantTypeEnum::jJSONObject) && instance.getRegisteredHotkeys().size())
		{
			current->data.push_back({ "hotkeys"s, move(instance.serializeHotkeys()) });
		}

		return builder;
	}

	BaseComposite::~BaseComposite()
	{
		vector<BaseComponent*> components;

		ranges::for_each(children, [&components](const unique_ptr<BaseComponent>& component) { components.push_back(component.get()); });

		ranges::for_each(components, [this](BaseComponent* component) { this->removeChild(component); });

		DestroyIcon(largeIcon);
		DestroyIcon(smallIcon);

		SendMessageW(handle, custom_window_messages::deinitTopLevelWindowPointer, NULL, NULL);
	}
}
