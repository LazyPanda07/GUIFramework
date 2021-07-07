#include "pch.h"
#include "BaseProgressBar.h"

using namespace std;

namespace gui_framework
{
	BaseProgressBar::BaseProgressBar(const wstring& progressBarName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseComponent
		(
			wstring(standard_classes::progressBar),
			progressBarName,
			settings,
			parent
		)
	{

	}

	void BaseProgressBar::update(int newPosition)
	{
		SendMessageW(handle, PBM_SETPOS, newPosition, NULL);
	}

	void BaseProgressBar::update()
	{
		SendMessageW(handle, PBM_STEPIT, NULL, NULL);
	}

	void BaseProgressBar::setUpdateStep(int updateStep)
	{
		SendMessageW(handle, PBM_SETSTEP, updateStep, NULL);
	}
}
