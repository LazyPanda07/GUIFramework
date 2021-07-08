#pragma once

#include "pch.h"

namespace gui_framework
{
	namespace interfaces
	{
		class GUI_FRAMEWORK_API IProgressBarColor
		{
		private:
			HWND progressBarHandle;
			COLORREF progressBarBackgroundColor;
			COLORREF progressBarColor;

		public:
			IProgressBarColor(HWND progressBarHandle);

			virtual void setProgressBarBackgroundColor(uint8_t red, uint8_t green, uint8_t blue) final;

			virtual void setProgressBarColor(uint8_t red, uint8_t green, uint8_t blue) final;

			virtual COLORREF getProgressBarBackgroundColor() const final;

			virtual COLORREF getProgressBarColor() const final;

			virtual ~IProgressBarColor() = default;
		};
	}
}
