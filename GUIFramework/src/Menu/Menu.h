#pragma once

#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Menu/IMenuItem.h"

namespace gui_framework
{
	class Menu
	{
	private:
		HMENU handle;
		BaseComponent* parent;
		std::vector<std::unique_ptr<interfaces::IMenuItem>> items;

	public:
		Menu(BaseComponent* parent);

		void addMenuItem(std::unique_ptr<interfaces::IMenuItem>&& item);

		void removeMenuItem(uint32_t index);

		const std::vector<std::unique_ptr<interfaces::IMenuItem>>& getItems() const;

		~Menu();
	};
}
