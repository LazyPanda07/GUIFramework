#pragma once

#include "pch.h"
#include "Menu/MenuItems/BaseMenuItem.h"

namespace gui_framework
{
	/// @brief Standard menu item
	class GUI_FRAMEWORK_API MenuItem : public BaseMenuItem
	{
	private:
		std::function<void()> onClick;

	public:
		MenuItem(const std::wstring& text, const std::function<void()>& onClick);

		void processMessage() override;

		~MenuItem() = default;
	};
}
