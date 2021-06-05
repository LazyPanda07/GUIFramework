#pragma once

#include "BaseComponents/BaseEditControl.h"
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
		EditControl(const std::wstring& editControlName, int x, int y, BaseComponent* parent, int width = standard_sizes::editControlWidth, int height = standard_sizes::editControlHeight);

		~EditControl() = default;
	};
}
