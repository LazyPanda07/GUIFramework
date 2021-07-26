#pragma once

#include "pch.h"
#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Components/ITextOperations.h"
#include "Styles/Components/Buttons/ButtonStyles.h"

namespace gui_framework
{
	/// @brief Base class for all buttons
	class GUI_FRAMEWORK_API BaseButton :
		public BaseComponent,
		public interfaces::ITextOperations
	{
	protected:
		// TODO: serialize onClick
		std::function<void()> onClick;

	protected:
		virtual LRESULT windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) override;

	public:
		BaseButton(const std::wstring& buttonName, const std::wstring& buttonText, const utility::ComponentSettings& settings, const styles::ButtonStyles& styles, BaseComponent* parent, const std::function<void()>& onClick = nullptr);

		virtual void setOnClick(const std::function<void()>& onClick) final;

		virtual const std::function<void()>& getOnClick() const final;

		/// @brief Not implemented
		/// @param red 
		/// @param green 
		/// @param blue 
		/// @exception NotImplemented Text color does not affects at button
		virtual void setTextColor(uint8_t red, uint8_t green, uint8_t blue) final override;

		~BaseButton() = default;
	};
}
