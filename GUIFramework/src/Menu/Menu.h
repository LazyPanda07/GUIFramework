#pragma once

#include "Interfaces/Menu/IMenuItem.h"

namespace gui_framework
{
	class Menu final
	{
	private:
		HMENU handle;
		std::vector<std::unique_ptr<interfaces::IMenuItem>> items;

	public:
		Menu() = default;

		Menu(HWND parent);

		Menu(const Menu&) = delete;

		Menu(Menu&& other) noexcept;

		Menu& operator = (const Menu&) = delete;

		Menu& operator = (Menu&& other) noexcept;

		void addMenuItem(std::unique_ptr<interfaces::IMenuItem>&& item);

		void removeMenuItem(uint32_t index);

		void handleMessage(uint32_t index);

		const std::vector<std::unique_ptr<interfaces::IMenuItem>>& getItems() const;

		HMENU getHandle() const;

		~Menu();
	};
}
