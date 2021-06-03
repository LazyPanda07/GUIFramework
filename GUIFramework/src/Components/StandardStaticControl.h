#pragma once

#include "BaseComponents/BaseStaticControl.h"

namespace gui_framework
{
	class StandardStaticControl : public BaseStaticControl
	{
	public:
		StandardStaticControl(const std::wstring& staticControlName, const std::wstring& editControlText, int x, int y, BaseComponent* parent, int width = standard_sizes::staticControlWidth, int height = standard_sizes::staticControlHeight);

		~StandardStaticControl() = default;
	};
}
