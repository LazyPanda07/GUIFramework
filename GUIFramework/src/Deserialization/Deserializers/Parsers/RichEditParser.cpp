#include "RichEditParser.h"

using namespace std;

namespace gui_framework
{
	namespace parsers
	{
		RichEditParser::RichEditParser() :
			callbacks({})
		{

		}

		void RichEditParser::parse(const json::utility::objectSmartPointer<json::utility::jsonObject>& description)
		{
			BaseComponentParser::parse(description);

			const auto& jsonCallbacks = description->getArray("callbacks");

			for (const auto& i : jsonCallbacks)
			{
				callbacks[i->getInt("callbackType")] = { i->getString("callbackName"), i->getString("callbackModule") };
			}
		}
	}
}
