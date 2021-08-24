#include "headers.h"
#include "SimpleComboBoxCreator.h"

#include "Components/ComboBoxes/SimpleComboBox.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* SimpleComboBoxCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			auto [values, onSelectionChange, functionName, moduleName] = any_cast<tuple<vector<wstring>, function<void(BaseComboBox&)>, string, string>>(additionalData);
			BaseComboBox* result = new SimpleComboBox(windowName, utility::ComponentSettings(settings.x, settings.y, settings.width, settings.height), parent);

			if (onSelectionChange)
			{
				result->setOnSelectionChange(onSelectionChange);
			}
			else if (functionName.size())
			{
				result->setOnSelectionChange(functionName, moduleName);
			}

			for (const auto& i : values)
			{
				result->addValue(i);
			}

			return result;
		}
	}
}
