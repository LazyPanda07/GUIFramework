#include "ListBoxCreator.h"

#include "Components/ListBoxes/ListBox.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* ListBoxCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComposite* parent)
		{
			auto [values, isSorting] = any_cast<tuple<vector<wstring>, bool>>(additionalData);
			
			BaseListBox* result = new ListBox(windowName, settings, parent, isSorting);

			for (const auto& i : values)
			{
				result->addValue(i);
			}

			return result;
		}
	}
}
