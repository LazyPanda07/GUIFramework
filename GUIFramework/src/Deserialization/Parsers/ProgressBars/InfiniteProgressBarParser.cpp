#include "InfiniteProgressBarParser.h"

using namespace std;

namespace gui_framework
{
	namespace parsers
	{
		void InfiniteProgressBarParser::parse(const json::utility::objectSmartPointer<json::utility::jsonObject>& description)
		{
			BaseComponentParser::parse(description);

			animationPeriod = static_cast<int>(description->getInt("animationPeriod"));
		}
	}
}
