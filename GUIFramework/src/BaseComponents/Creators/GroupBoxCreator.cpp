#include "pch.h"
#include "GroupBoxCreator.h"

#include "Components/GroupBox.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* GroupBoxCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			auto [groupBoxClassName, groupBoxFunctionName, data] = any_cast<tuple<wstring, string, vector<GroupBox::radioButtonData>>>(additionalData);

			GroupBox* result = new GroupBox(groupBoxClassName, windowName, settings.x, settings.y, settings.width, settings.height, parent, groupBoxFunctionName);

			for (const auto& i : data)
			{
				result->addRadioButton(i);
			}

			return result;
		}
	}
}
