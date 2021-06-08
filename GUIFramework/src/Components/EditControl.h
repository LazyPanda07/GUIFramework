#pragma once

#include "BaseComponents/StandardComponents/BaseEditControl.h"
#include "BaseComponents/BaseResizableComponent.h"

namespace gui_framework
{
	/// @brief Standard edit control
	class EditControl :
		public BaseResizableComponent,
		public BaseEditControl
	{
	private:
		LRESULT preWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) override;

	public:
		EditControl(const std::wstring& editControlName, int x, int y, BaseComponent* parent, uint16_t width = standard_sizes::editControlWidth, uint16_t height = standard_sizes::editControlHeight);

		~EditControl() = default;
	};
}
