#pragma once

#include "Interfaces/Menu/IMenuItem.h"

namespace gui_framework
{
	class Menu final
	{
	private:
		std::wstring name;
		HMENU handle;
		std::vector<std::unique_ptr<interfaces::IMenuItem>> items;

	public:
		Menu() = default;

		Menu(const std::wstring& name, HWND parent);

		Menu(const Menu&) = delete;

		Menu(Menu&& other) noexcept;

		Menu& operator = (const Menu&) = delete;

		Menu& operator = (Menu&& other) noexcept;

		/// @brief Also calls item's createMenuItem method
		/// @return self
		Menu& addMenuItem(std::unique_ptr<interfaces::IMenuItem>&& item);

		void removeMenuItem(uint32_t index);

		void handleMessage(uint32_t index);

		const std::wstring& getName() const;

		const std::vector<std::unique_ptr<interfaces::IMenuItem>>& getItems() const;

		HMENU getHandle() const;

		~Menu();
	};
}
