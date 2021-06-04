#pragma once

#include "BaseComponents/BaseStaticControl.h"

namespace gui_framework
{
	class StaticControl : public BaseStaticControl
	{
	public:
		StaticControl(const std::wstring& staticControlName, const std::wstring& editControlText, int x, int y, BaseComponent* parent, int width = standard_sizes::staticControlWidth, int height = standard_sizes::staticControlHeight);

		~StaticControl() = default;
	};
}
