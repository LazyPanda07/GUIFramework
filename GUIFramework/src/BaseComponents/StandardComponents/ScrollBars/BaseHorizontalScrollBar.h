#pragma once

#include "BaseScrollBar.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API BaseHorizontalScrollBar : public BaseScrollBar
	{
	public:
		BaseHorizontalScrollBar(const std::wstring& scrollBarName, const utility::ComponentSettings& settings, BaseComponent* parent);

		virtual ~BaseHorizontalScrollBar() = default;
	};
}
