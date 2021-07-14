#include "pch.h"
#include "DropDownComboBoxCreator.h"

#include "Components/DropDownComboBox.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* DropDownComboBoxCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			BaseComboBox* result = new DropDownComboBox(windowName, utility::ComponentSettings(settings.x, settings.y, settings.width, settings.height), parent);

			vector<wstring> values = any_cast<vector<wstring>>(additionalData);

			for (const auto& i : values)
			{
				result->addValue(i);
			}

			return result;
		}
	}
}
