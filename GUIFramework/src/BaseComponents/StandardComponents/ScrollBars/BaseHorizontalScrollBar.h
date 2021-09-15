#pragma once

#include "BaseScrollBar.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API BaseHorizontalScrollBar : public BaseScrollBar
	{
	public:
		BaseHorizontalScrollBar(const std::wstring& scrollBarName, const utility::ComponentSettings& settings, BaseComponent* parent);

		/// @brief Used as key in creators
		/// @return typeid().hash_code()
		virtual size_t getHash() const override = 0;

		virtual ~BaseHorizontalScrollBar() = default;
	};
}
