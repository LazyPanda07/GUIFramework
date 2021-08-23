#include "headers.h"
#include "DropDownListComboBoxCreator.h"

#include "Components/ComboBoxes/DropDownListComboBox.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* DropDownListComboBoxCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			BaseComboBox* result = new DropDownListComboBox(windowName, utility::ComponentSettings(settings.x, settings.y, settings.width, settings.height), parent);

			vector<wstring> values = any_cast<vector<wstring>>(additionalData);

			for (const auto& i : values)
			{
				result->addValue(i);
			}

			return result;
		}
	}
}
