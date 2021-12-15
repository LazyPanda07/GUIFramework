#include "headers.h"
#include "Menu.h"

#include "Utility/Utility.h"

using namespace std;

namespace gui_framework
{
	Menu::Menu() :
		handle(nullptr),
		parent(nullptr)
	{

	}

	Menu::Menu(const wstring& name, HWND parent) :
		name(name),
		handle(CreateMenu()),
		parent(parent)
	{
		MENUINFO info = {};

		info.cbSize = sizeof(info);
		info.dwStyle = MNS_NOTIFYBYPOS;
		info.fMask = MIM_STYLE;

		SetMenuInfo(handle, &info);

		if (parent)
		{
			SetMenu(parent, handle);
		}
	}

	Menu::Menu(Menu&& other) noexcept :
		name(move(other.name)),
		handle(other.handle),
		items(move(other.items)),
		parent(other.parent)
	{
		other.handle = nullptr;
		other.parent = nullptr;
	}

	Menu& Menu::operator = (Menu&& other) noexcept
	{
		name = move(other.name);
		handle = other.handle;
		items = move(other.items);
		parent = other.parent;

		other.handle = nullptr;
		other.parent = nullptr;

		return *this;
	}

	Menu& Menu::addMenuItem(unique_ptr<interfaces::IMenuItem>&& item)
	{
		items.push_back(move(item));

		items.back()->createMenuItem(handle);
		items.back()->setIndex(static_cast<uint32_t>(items.size() - 1));

		this->updateMenu();

		return *this;
	}

	void Menu::removeMenuItem(uint32_t index)
	{
		items.erase(items.begin() + index);

		for (uint32_t i = index; i < items.size(); i++)
		{
			items[i]->setIndex(i);
		}

		this->updateMenu();
	}

	void Menu::handleMessage(uint32_t index)
	{
		items[index]->processMessage();
	}

	void Menu::updateMenu() const
	{
		DrawMenuBar(parent);
	}

	const wstring& Menu::getName() const
	{
		return name;
	}

	const vector<unique_ptr<interfaces::IMenuItem>>& Menu::getItems() const
	{
		return items;
	}

	HMENU Menu::getHandle() const
	{
		return handle;
	}

	json::JSONBuilder Menu::getStructure() const
	{
		uint32_t codepage = ISerializable::getCodepage();
		json::JSONBuilder builder(codepage);

		vector<json::utility::objectSmartPointer<json::utility::jsonObject>> children;

		for (const auto& i : items)
		{
			json::utility::objectSmartPointer<json::utility::jsonObject> child = json::utility::make_object<json::utility::jsonObject>();
			json::JSONBuilder structure = i->getStructure();

			const string& itemText = get<string>(structure["itemText"]);
			const string& itemType = get<string>(structure["itemType"]);

			child->data.push_back({ "itemText"s, itemText });
			child->data.push_back({ "itemType"s, itemType });

			if (structure.contains("functionName", json::utility::variantTypeEnum::jString))
			{
				child->data.push_back({ "functionName"s, get<string>(structure["functionName"]) });
				child->data.push_back({ "moduleName"s, get<string>(structure["moduleName"]) });
			}

			if (itemType == standard_menu_items::dropDownMenuItem)
			{
				child->data.push_back({ "popupId"s, get<uint64_t>(structure["popupId"]) });
			}

			json::utility::appendArray(move(child), children);
		}

		builder.
			append("menuName"s, utility::to_string(name, codepage)).
			append("menuId"s, reinterpret_cast<uint64_t>(handle)).
			append("items"s, move(children));

		return builder;
	}

	Menu::~Menu()
	{
		DestroyMenu(handle);
	}
}
