#include "core.h"
#include "IProgressBarColor.h"

using namespace std;

namespace gui_framework
{
	namespace interfaces
	{
		IProgressBarColor::IProgressBarColor(HWND progressBarHandle) :
			progressBarHandle(progressBarHandle),
			progressBarBackgroundColor(RGB(0, 255, 0)),
			progressBarColor(RGB(0, 255, 0))
		{

		}

		void IProgressBarColor::setProgressBarBackgroundColor(uint8_t red, uint8_t green, uint8_t blue)
		{
			progressBarBackgroundColor = RGB(red, green, blue);

			SetWindowTheme(progressBarHandle, L"", L"");

			SendMessageW(progressBarHandle, PBM_SETBKCOLOR, NULL, static_cast<LPARAM>(progressBarBackgroundColor));

			InvalidateRect(progressBarHandle, nullptr, true);
		}

		void IProgressBarColor::setProgressBarColor(uint8_t red, uint8_t green, uint8_t blue)
		{
			progressBarColor = RGB(red, green, blue);

			SetWindowTheme(progressBarHandle, L"", L"");

			SendMessageW(progressBarHandle, PBM_SETBARCOLOR, NULL, static_cast<LPARAM>(progressBarColor));

			InvalidateRect(progressBarHandle, nullptr, true);
		}

		COLORREF IProgressBarColor::getProgressBarBackgroundColor() const
		{
			return progressBarBackgroundColor;
		}

		COLORREF IProgressBarColor::getProgressBarColor() const
		{
			return progressBarColor;
		}
	}
}
