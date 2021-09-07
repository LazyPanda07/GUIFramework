#pragma once

#include "BaseVerticalScrollBar.h"
#include "BaseHorizontalScrollBar.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API BaseVerticalAndHorizontalScrollBar : public BaseScrollBar
	{
	public:
		BaseVerticalAndHorizontalScrollBar(const std::wstring& scrollBarName, const utility::ComponentSettings& settings, BaseComponent* parent);

		virtual ~BaseVerticalAndHorizontalScrollBar() = default;
	};
}
