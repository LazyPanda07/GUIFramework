#pragma once

#include "BaseComponents/BaseComponent.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API BaseInfiniteProgressBar : virtual public BaseComponent
	{
	protected:
		int animationPeriod;

	public:
		/// @brief 
		/// @param progressBarName 
		/// @param settings 
		/// @param parent 
		/// @param animationPeriod Period between animation in milliseconds
		BaseInfiniteProgressBar(const std::wstring& progressBarName, const utility::ComponentSettings& settings, BaseComponent* parent, int animationPeriod = NULL);

		virtual void playAnimation() final;

		virtual void stopAnimation() final;

		/// @brief 
		/// @param animationPeriod Period between animation in milliseconds
		virtual void setAnimationPeriod(int animationPeriod) final;

		virtual int getAnimationPeriod() const final;

		virtual ~BaseInfiniteProgressBar() = default;
	};
}
