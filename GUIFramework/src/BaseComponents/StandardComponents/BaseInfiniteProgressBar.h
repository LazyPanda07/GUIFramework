#pragma once

#include "pch.h"
#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Components/IProgressBarColor.h"

namespace gui_framework
{
	/// @brief Base class for all non updatable progress bars
	class GUI_FRAMEWORK_API BaseInfiniteProgressBar : 
		public BaseComponent,
		public interfaces::IProgressBarColor
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

		/// @brief Same as setProgressBarBackgroundColor
		/// @param red 
		/// @param green 
		/// @param blue 
		virtual void setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue) final override;

		/// @brief Inherited from IProgressBarColor
		/// @param red 
		/// @param green 
		/// @param blue 
		virtual void setProgressBarBackgroundColor(uint8_t red, uint8_t green, uint8_t blue) final override;

		/// @brief Not implemented
		/// @param red 
		/// @param green 
		/// @param blue 
		/// @exception NotImplemented Text color does not affects at progress bar
		virtual void setTextColor(uint8_t red, uint8_t green, uint8_t blue) final override;

		virtual ~BaseInfiniteProgressBar() = default;
	};
}
