#pragma once

#include "BaseComponents/StandardComponents/BaseButton.h"
#include "BaseComponents/BaseResizableComponent.h"

#pragma warning(push)
#pragma warning(disable: 4250)

namespace gui_framework
{
	/// @brief Standard button
	class GUI_FRAMEWORK_API Button :
		public BaseResizableComponent,
		public BaseButton
	{
	private:
		LRESULT preWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) override;

	public:
		Button(const std::wstring& buttonName, const std::wstring& buttonText, int x, int y, BaseComponent* parent, const std::function<void()>& onClick = nullptr, uint16_t width = standard_sizes::buttonWidth, uint16_t height = standard_sizes::buttonHeight);

		~Button() = default;
	};
}

#pragma warning(pop)
