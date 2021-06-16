#include "pch.h"
#include "Menu.h"

using namespace std;

namespace gui_framework
{
	Menu::Menu(HWND parent) :
		handle(CreateMenu())
	{
		MENUINFO info = {};

		info.cbSize = sizeof(info);
		info.dwStyle = MIM_APPLYTOSUBMENUS | MNS_NOTIFYBYPOS;
		info.fMask = MIM_STYLE;

		SetMenuInfo(handle, &info);

		SetMenu(parent, handle);
	}

	Menu::Menu(Menu&& other) noexcept :
		handle(other.handle),
		items(move(other.items))
	{
		other.handle = nullptr;
	}

	Menu& Menu::operator = (Menu&& other) noexcept
	{
		handle = other.handle;
		items = move(other.items);

		other.handle = nullptr;

		return *this;
	}

	void Menu::addMenuItem(unique_ptr<interfaces::IMenuItem>&& item)
	{
		items.back()->setParent(handle);
		items.back()->setIndex(static_cast<uint32_t>(items.size()));

		items.push_back(move(item));
	}

	void Menu::removeMenuItem(uint32_t index)
	{
		items.erase(items.begin() + index);

		for (uint32_t i = index; i < items.size(); i++)
		{
			items[i]->setIndex(i);
		}
	}

	void Menu::handleMessage(uint32_t index)
	{
		items[index]->processMessage();
	}

	const vector<unique_ptr<interfaces::IMenuItem>>& Menu::getItems() const
	{
		return items;
	}

	HMENU Menu::getHandle() const
	{
		return handle;
	}

	Menu::~Menu()
	{
		DestroyMenu(handle);
	}
}
