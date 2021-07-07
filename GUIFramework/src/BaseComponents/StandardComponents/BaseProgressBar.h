#pragma once

#include "BaseComponents/BaseComponent.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API BaseProgressBar : virtual public BaseComponent
	{
	public:
		BaseProgressBar(const std::wstring& progressBarName, const utility::ComponentSettings& settings, BaseComponent* parent);

		virtual void update(int newPosition) final;

		virtual void update() final;

		virtual void setUpdateStep(int updateStep) final;

		virtual ~BaseProgressBar() = default;
	};
}
