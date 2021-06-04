#pragma once

#include "BaseComponents/BaseButton.h"
#include "BaseComponents/BaseResizableComponent.h"

namespace gui_framework
{
	/// @brief Standard button
	class Button :
		public BaseResizableComponent,
		public BaseButton
	{
	public:
		Button(const std::wstring& buttonName, const std::wstring& buttonText, int x, int y, BaseComponent* parent, uint64_t buttonId, const std::function<LRESULT(WPARAM, LPARAM)>& onClick = nullptr, int width = standard_sizes::buttonWidth, int height = standard_sizes::buttonHeight);

		LRESULT windowMessagesHandle(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam, bool& isUsed) override;

		~Button() = default;
	};
}