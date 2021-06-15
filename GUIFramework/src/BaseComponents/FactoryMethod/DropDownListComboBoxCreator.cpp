#include "pch.h"
#include "DropDownListComboBoxCreator.h"

#include "Components/DropDownListComboBox.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* DropDownListComboBoxCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			BaseComboBox* result = new DropDownListComboBox(windowName, settings.x, settings.y, settings.width, settings.height, parent);

			try
			{
				vector<wstring> values = any_cast<vector<wstring>>(additionalData);

				for (const auto& i : values)
				{
					result->addValue(i);
				}
			}
			catch (const std::exception&)
			{

			}

			return result;
		}
	}
}
