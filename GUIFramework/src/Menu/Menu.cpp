#include "pch.h"
#include "Menu.h"

using namespace std;

namespace gui_framework
{
	Menu::Menu(BaseComponent* parent) :
		handle(CreateMenu()),
		parent(parent)
	{
		SetMenu(parent->getHandle(), handle);
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

	const vector<unique_ptr<interfaces::IMenuItem>>& Menu::getItems() const
	{
		return items;
	}

	Menu::~Menu()
	{
		DestroyMenu(handle);
	}
}
