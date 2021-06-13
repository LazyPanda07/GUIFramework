#pragma once

#include "BaseComponents/StandardComponents/BaseButton.h"
#include "BaseComponents/BaseResizableComponent.h"

namespace gui_framework
{
	/// @brief Standard button
	class Button :
		public BaseResizableComponent,
		public BaseButton
	{
	private:
		LRESULT preWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) override;

	public:
		Button(const std::wstring& buttonName, const std::wstring& buttonText, int x, int y, BaseComponent* parent, const std::function<LRESULT(WPARAM, LPARAM)>& onClick = nullptr, uint16_t width = standard_sizes::buttonWidth, uint16_t height = standard_sizes::buttonHeight);

		LRESULT windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) override;

		~Button() = default;
	};
}
