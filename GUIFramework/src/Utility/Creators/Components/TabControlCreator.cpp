#include "headers.h"
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
					if (i.functionName.empty())
					{
						result->appendTextAndImage(i.text, i.pathToImage, i.callback);
					}
					else
					{
						result->appendTextAndImage(i.text, i.pathToImage, i.functionName, i.moduleName);
					}
				}
				else if (i.text.size())
				{
					if (i.functionName.empty())
					{
						result->appendText(i.text, i.callback);
					}
					else
					{
						result->appendText(i.text, i.functionName, i.moduleName);
					}
				}
				else if (!i.pathToImage.empty())
				{
					if (i.functionName.empty())
					{
						result->appendImage(i.pathToImage, i.callback);
					}
					else
					{
						result->appendImage(i.pathToImage, i.functionName, i.moduleName);
					}
				}
			}

			return result;
		}
	}
}
