#include "pch.h"
#include "ProgressBarAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		AdditionalCreationData<ProgressBar>::AdditionalCreationData(int updateStep) :
			updateStep(updateStep)
		{

		}

		any AdditionalCreationData<ProgressBar>::getData() const
		{
			return make_any<int>(updateStep);
		}
	}
}
