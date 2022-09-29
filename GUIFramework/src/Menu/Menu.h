#pragma once

#include "core.h"
#include "Interfaces/Menu/IMenuItem.h"

namespace gui_framework
{
	/// @brief Menu class
	class GUI_FRAMEWORK_API Menu final : public interfaces::ISerializable
	{
	private:
		std::wstring name;
		HMENU handle;
		HWND parent;
		std::vector<std::unique_ptr<interfaces::IMenuItem>> items;

	public:
		Menu();

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

		void updateMenu() const;

		const std::wstring& getName() const;

		const std::vector<std::unique_ptr<interfaces::IMenuItem>>& getItems() const;

		HMENU getHandle() const;

		json::JSONBuilder getStructure() const override;

		~Menu();
	};
}
