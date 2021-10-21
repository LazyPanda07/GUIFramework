#pragma once

#include "BaseVerticalScrollBar.h"
#include "BaseHorizontalScrollBar.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API BaseVerticalAndHorizontalScrollBar : public BaseScrollBar
	{
	public:
		BaseVerticalAndHorizontalScrollBar(const std::wstring& scrollBarName, const utility::ComponentSettings& settings, BaseComponent* parent);

		/// @brief Used as key in creators
		/// @return typeid().hash_code()
		virtual size_t getHash() const override = 0;

		virtual ~BaseVerticalAndHorizontalScrollBar() = default;
	};
}
