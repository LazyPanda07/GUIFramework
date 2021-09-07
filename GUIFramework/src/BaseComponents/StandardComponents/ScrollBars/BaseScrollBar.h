#pragma once

#include "BaseComponents/BaseComponent.h"
#include "Styles/Components/ScrollBars/ScrollBarStyles.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API BaseScrollBar : public BaseComponent
	{
	public:
		BaseScrollBar(const std::wstring& scrollBarName, const utility::ComponentSettings& settings, const styles::ScrollBarStyles& styles, BaseComponent* parent);

		virtual ~BaseScrollBar() = default;
	};
}
