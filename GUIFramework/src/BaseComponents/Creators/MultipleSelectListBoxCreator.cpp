#include "pch.h"
#include "MultipleSelectListBoxCreator.h"

#include "Components/ListBoxes/MultipleSelectListBox.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* MultipleSelectListBoxCreator::create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent)
		{
			auto [values, isSorting] = any_cast<tuple<vector<wstring>, bool>>(additionalData);

			BaseListBox* result = new MultipleSelectListBox(windowName, utility::ComponentSettings(settings.x, settings.y, settings.width, settings.height), parent, isSorting);

			for (const auto& i : values)
			{
				result->addValue(i);
			}

			return result;
		}
	}
}
