#pragma once

#include "BaseScrollBar.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API BaseVerticalScrollBar : public BaseScrollBar
	{
	public:
		BaseVerticalScrollBar(const std::wstring& scrollBarName, const utility::ComponentSettings& settings, BaseComponent* parent);

		virtual ~BaseVerticalScrollBar() = default;
	};
}
