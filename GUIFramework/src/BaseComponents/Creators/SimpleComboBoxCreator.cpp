#include "pch.h"
#include "SimpleComboBoxCreator.h"

#include "Components/SimpleComboBox.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* SimpleComboBoxCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			BaseComboBox* result = new SimpleComboBox(windowName, settings.x, settings.y, settings.width, settings.height, parent);

			vector<wstring> values = any_cast<vector<wstring>>(additionalData);

			for (const auto& i : values)
			{
				result->addValue(i);
			}

			return result;
		}
	}
}