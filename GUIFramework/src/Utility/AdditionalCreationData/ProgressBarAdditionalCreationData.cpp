#include "core.h"
#include "ProgressBarAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		AdditionalCreationData<ProgressBar>::AdditionalCreationData(int minRange, int maxRange, int updateStep) :
			minRange(minRange),
			maxRange(maxRange),
			updateStep(updateStep)
		{

		}

		any AdditionalCreationData<ProgressBar>::getData() const
		{
			return make_any<tuple<int, int, int>>(minRange, maxRange, updateStep);
		}

		AdditionalCreationData<InfiniteProgressBar>::AdditionalCreationData(int animationPeriod) :
			animationPeriod(animationPeriod)
		{

		}

		any AdditionalCreationData<InfiniteProgressBar>::getData() const
		{
			return make_any<int>(animationPeriod);
		}
	}
}
