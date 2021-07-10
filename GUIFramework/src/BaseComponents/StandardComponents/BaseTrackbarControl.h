#pragma once

#include "BaseComponents/BaseComponent.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API BaseTrackbarControl : virtual public BaseComponent
	{
	public:
		BaseTrackbarControl(const std::wstring& trackbarName, const utility::ComponentSettings& settings, BaseComponent* parent);

		virtual ~BaseTrackbarControl() = default;
	};
}
