#pragma once

#include "BaseComponents/BaseEditControl.h"

namespace gui_framework
{
	/// @brief Standard edit control
	class StandardEditControl : public BaseEditControl
	{
	public:
		StandardEditControl(const std::wstring& editControlName, int x, int y, BaseComponent* parent, int width = standard_sizes::editControlWidth, int height = standard_sizes::editControlHeight);

		~StandardEditControl() = default;
	};
}
