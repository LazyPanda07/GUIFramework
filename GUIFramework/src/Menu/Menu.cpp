#include "pch.h"
#include "Menu.h"

using namespace std;

namespace gui_framework
{
	Menu::Menu(const wstring& name, HWND parent) :
		name(name),
		handle(CreateMenu())
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

	Menu& Menu::addMenuItem(unique_ptr<interfaces::IMenuItem>&& item)
	{
		items.push_back(move(item));

		items.back()->createMenuItem(handle);
		items.back()->setIndex(static_cast<uint32_t>(items.size() - 1));

		return *this;
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

	Menu::~Menu()
	{
		DestroyMenu(handle);
	}
}
