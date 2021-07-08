#pragma once

#include "BaseComponents/StandardComponents/BaseAnimationControl.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API AnimationControl : public BaseAnimationControl
	{
	public:
		AnimationControl(const std::wstring& animationControlName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, bool isCentered = true, bool isAutoPlay = false);

		~AnimationControl() = default;
	};
}
