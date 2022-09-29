#pragma once

#include "BaseComponents/BaseComponent.h"
#include "Styles/Components/ScrollBars/ScrollBarStyles.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API BaseScrollBar : public BaseComponent
	{
	public:
		BaseScrollBar(const std::wstring& scrollBarName, const utility::ComponentSettings& settings, const styles::ScrollBarStyles& styles, BaseComposite* parent);

		/// @brief Used as key in creators
		/// @return typeid().hash_code()
		virtual size_t getHash() const override = 0;

		virtual ~BaseScrollBar() = default;
	};
}
