#pragma once

#include "BaseComponents/StandardComponents/BaseStaticControl.h"
#include "BaseComponents/BaseResizableComponent.h"

namespace gui_framework
{
	/// @brief Standard static control
	class GUI_FRAMEWORK_API StaticControl :
		public BaseResizableComponent,
		public BaseStaticControl
	{
	private:
		LRESULT preWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) override;

	public:
		StaticControl(const std::wstring& staticControlName, const std::wstring& editControlText, int x, int y, BaseComponent* parent, uint16_t width = standard_sizes::staticControlWidth, uint16_t height = standard_sizes::staticControlHeight);

		~StaticControl() = default;
	};
}
