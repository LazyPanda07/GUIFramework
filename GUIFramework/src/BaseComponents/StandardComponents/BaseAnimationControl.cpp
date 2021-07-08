#include "pch.h"
#include "BaseAnimationControl.h"

#include "Exceptions/FileDoesNotExist.h"

using namespace std;

namespace gui_framework
{
	BaseAnimationControl::BaseAnimationControl(const wstring& animationControlName, const utility::ComponentSettings& settings, BaseComponent* parent, bool isCentered, bool isAutoPlay) :
		BaseComponent
		(
			wstring(standard_classes::animateControl),
			animationControlName,
			settings,
			parent
		)
	{
		if (isAutoPlay)
		{
			utility::appendStyle(handle, ACS_AUTOPLAY);
		}

		if (isCentered)
		{
			utility::appendStyle(handle, ACS_CENTER);
		}
	}

	bool BaseAnimationControl::openAnimation(const filesystem::path& pathToAVIAnimationFile)
	{
		if (!filesystem::exists(pathToAVIAnimationFile))
		{
			throw exceptions::FileDoesNotExist(pathToAVIAnimationFile);
		}

		return SendMessageW(handle, ACM_OPEN, NULL, reinterpret_cast<LPARAM>(pathToAVIAnimationFile.wstring().data()));
	}

	bool BaseAnimationControl::playAnimation(int repeatCount)
	{
		return SendMessageW(handle, ACM_PLAY, repeatCount, MAKELONG(0, -1));
	}

	bool BaseAnimationControl::stopAnimation()
	{
		return SendMessageW(handle, ACM_STOP, NULL, NULL);
	}
}
