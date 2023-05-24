#include "MainWindowParser.h"

using namespace std;

namespace gui_framework
{
	namespace parsers
	{
		MainWindowParser::MainWindowParser() :
			trayIconResource(NULL)
		{

		}

		void MainWindowParser::parse(const json::utility::jsonObject& description)
		{
			SeparateWindowParser::parse(description);

			uint32_t codepage = interfaces::ISerializable::getCodepage();

			if (description.contains("trayIconResource", json::utility::variantTypeEnum::jInt64_t))
			{
				trayIconResource = static_cast<uint16_t>(description.getInt("trayIconResource"));

				if (description.contains("items", json::utility::variantTypeEnum::jJSONArray))
				{
					for (const json::utility::jsonObject& item : description.getArray("items"))
					{
						items.emplace_back
						(
							utility::to_wstring(item.getString("text"), codepage),
							BaseMainWindow::Function(item.getString("functionName"), item.getString("moduleName"))
						);
					}
				}
			}
		}
	}
}