#pragma once

#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Components/ITextOperations.h"

namespace gui_framework
{
	/// @brief Base class for all buttons
	class GUI_FRAMEWORK_API BaseButton :
		virtual public BaseComponent,
		public interfaces::ITextOperations
	{
	protected:
		std::function<LRESULT(WPARAM, LPARAM)> onClick;

	public:
		BaseButton(const std::wstring& buttonName, const std::wstring& buttonText, const utility::ComponentSettings& settings, BaseComponent* parent, const std::function<LRESULT(WPARAM, LPARAM)>& onClick = nullptr);

		virtual LRESULT windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) final;

		virtual void setOnClick(const std::function<LRESULT(WPARAM, LPARAM)>& onClick) final;

		virtual const std::function<LRESULT(WPARAM, LPARAM)>& getOnClick() const final;

		/// @brief Not implemented
		/// @param red 
		/// @param green 
		/// @param blue 
		/// @exception gui_framework::exceptions::NotImplemented Background color does not affects at combo boxes
		virtual void setTextColor(uint8_t red, uint8_t green, uint8_t blue) final override;

		~BaseButton() = default;
	};
}
