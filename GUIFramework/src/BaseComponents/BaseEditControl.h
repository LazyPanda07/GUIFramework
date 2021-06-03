#pragma once

#include "BaseComponent.h"

namespace gui_framework
{
	/// @brief Base class for all edit controls
	class BaseEditControl : public BaseComponent
	{
	public:
		BaseEditControl(const std::wstring& editControlName, const utility::ComponentSettings& settings, BaseComponent* parent);

		virtual void setText(const std::wstring& text) const final;

		/// @brief Get text from edit control
		/// @return Text from edit control
		/// @exception gui_framework::exceptions::GetLastErrorException
		virtual std::wstring getText() const final;

		virtual ~BaseEditControl() = default;
	};
}
