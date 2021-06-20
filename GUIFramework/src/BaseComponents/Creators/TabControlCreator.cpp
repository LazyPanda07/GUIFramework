#include "pch.h"
#include "TabControlCreator.h"

#include "Components/TabControl.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* TabControlCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			auto [data, imagesWidth, imagesHeight] = any_cast<tuple<vector<TabControl::tabData>, uint16_t, uint16_t>>(additionalData);

			TabControl* result = new TabControl(windowName, settings, parent, imagesWidth, imagesHeight);

			for (const auto& i : data)
			{
				if (i.text.size() && !i.pathToImage.empty())
				{
					result->appendTextAndImage(i.text, i.pathToImage, i.callback);
				}
				else if (i.text.size())
				{
					result->appendText(i.text, i.callback);
				}
				else if (!i.pathToImage.empty())
				{
					result->appendImage(i.pathToImage, i.callback);
				}
			}

			return result;
		}
	}
}
