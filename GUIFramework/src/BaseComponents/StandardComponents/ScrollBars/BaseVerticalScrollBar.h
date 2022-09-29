#pragma once

#include "BaseScrollBar.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API BaseVerticalScrollBar : public BaseScrollBar
	{
	public:
		BaseVerticalScrollBar(const std::wstring& scrollBarName, const utility::ComponentSettings& settings, BaseComposite* parent);

		/// @brief Used as key in creators
		/// @return typeid().hash_code()
		virtual size_t getHash() const override = 0;

		virtual ~BaseVerticalScrollBar() = default;
	};
}
