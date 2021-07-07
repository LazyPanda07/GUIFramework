#pragma once

#include "BaseComponents/BaseComponent.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API BaseInfiniteProgressBar : virtual public BaseComponent
	{
	public:
		BaseInfiniteProgressBar(const std::wstring& progressBarName, const utility::ComponentSettings& settings, BaseComponent* parent);

		virtual ~BaseInfiniteProgressBar() = default;
	};
}
