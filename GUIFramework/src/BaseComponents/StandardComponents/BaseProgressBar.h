#pragma once

#include "pch.h"
#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Components/IProgressBarColor.h"

namespace gui_framework
{
	/// @brief Base class for all updatable progress bars
	class GUI_FRAMEWORK_API BaseProgressBar : 
		public BaseComponent,
		public interfaces::IProgressBarColor
	{
	public:
		static inline constexpr int defaultUpdateStep = 10;
		static inline constexpr int defaultMinRange = 0;
		static inline constexpr int defaultMaxRange = 100;

	protected:
		int minRange;
		int maxRange;
		int updateStep;

	public:
		BaseProgressBar(const std::wstring& progressBarName, const utility::ComponentSettings& settings, BaseComponent* parent, int minRange = defaultMinRange, int maxRange = defaultMaxRange, int updateStep = defaultUpdateStep);

		virtual void update(int newPosition) final;

		virtual void update() final;

		virtual void advancePosition(int position) final;

		virtual void setMinRange(int minRange) final;

		virtual void setMaxRange(int maxRange) final;

		virtual void setUpdateStep(int updateStep) final;

		virtual int getMinRange() const final;

		virtual int getMaxRange() const final;

		virtual int getUpdateStep() const final;

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

		virtual json::JSONBuilder getStructure() const override;

		virtual ~BaseProgressBar() = default;
	};
}
