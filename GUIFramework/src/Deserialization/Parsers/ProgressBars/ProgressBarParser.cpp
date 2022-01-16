#include "ProgressBarParser.h"

using namespace std;

namespace gui_framework
{
	namespace parsers
	{
		void ProgressBarParser::parse(const json::utility::jsonObject& description)
		{
			BaseComponentParser::parse(description);

			minRange = static_cast<int>(description.getInt("minRange"));
			maxRange = static_cast<int>(description.getInt("maxRange"));

			updateStep = static_cast<int>(description.getInt("updateStep"));
		}
	}
}
