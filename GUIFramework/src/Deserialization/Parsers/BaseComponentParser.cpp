#include "BaseComponentParser.h"

#include "Utility/Utility.h"
#include "Interfaces/Utility/ISerializable.h"
#include "Interfaces/Styles/IStyles.h"

using namespace std;

namespace gui_framework
{
	namespace parsers
	{
		BaseComponentParser::BaseComponentParser() :
			backgroundColor{ 255, 255, 255 },
			textColor{ 0, 0, 0 }
		{

		}

		void BaseComponentParser::parse(const json::utility::objectSmartPointer<json::utility::jsonObject>& description)
		{
			using json::utility::objectSmartPointer;
			using json::utility::jsonObject;

			uint32_t codepage = interfaces::ISerializable::getCodepage();

			className = utility::to_wstring(description->getString("className"), CP_UTF8);
			settings.x = static_cast<int>(description->getInt("desiredX"));
			settings.y = static_cast<int>(description->getInt("desiredY"));
			settings.width = static_cast<uint16_t>(description->getUnsignedInt("desiredWidth"));
			settings.height = static_cast<uint16_t>(description->getUnsignedInt("desiredHeight"));
			settings.styles = interfaces::IStyles(description->getInt("styles"), description->getInt("extendedStyles"));

			const auto& temBackgroundColor = json::utility::JSONArrayWrapper(description->getArray("backgroundColor")).getAsInt64_tArray();
			const auto& temTextColor = json::utility::JSONArrayWrapper(description->getArray("textColor")).getAsInt64_tArray();;

			for (size_t i = 0; i < temBackgroundColor.size(); i++)
			{
				backgroundColor[i] = static_cast<uint8_t>(temBackgroundColor[i]);
			}

			for (size_t i = 0; i < temTextColor.size(); i++)
			{
				textColor[i] = static_cast<uint8_t>(temTextColor[i]);
			}
		}
	}
}
