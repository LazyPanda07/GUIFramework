#pragma once

#include "Menu/MenuItems/BaseMenuItem.h"

namespace gui_framework
{
	class MenuItem : public BaseMenuItem
	{
	private:
		std::function<void()> onClick;

	public:
		MenuItem(const std::wstring& text, const std::function<void()>& onClick);

		void processMessage() override;

		~MenuItem() = default;
	};
}
