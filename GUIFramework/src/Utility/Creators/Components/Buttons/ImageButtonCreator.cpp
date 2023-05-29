#include "ImageButtonCreator.h"

#include "Components/Buttons/ImageButton.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* ImageButtonCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComposite* parent)
		{
			auto [text, pathToImage, imageResource, resourceModuleName, imageWidth, imageHeight, dType, iType, onClick, onClickFunctionName, onClickFunctionModule] =
				any_cast<tuple<wstring, filesystem::path, uint32_t, string, uint16_t, uint16_t, ImageButton::drawingType, ImageButton::imageType, function<void()>, string, string>>(additionalData);
			
			if (pathToImage.empty())
			{
				return onClickFunctionName.empty() ?
					new ImageButton(windowName, imageResource, dType, iType, imageWidth, imageHeight, settings, parent, onClick, resourceModuleName) :
					new ImageButton(windowName, imageResource, dType, iType, imageWidth, imageHeight, settings, parent, onClickFunctionName, onClickFunctionModule, resourceModuleName);
			}

			return onClickFunctionName.empty() ?
				new ImageButton(windowName, pathToImage, dType, iType, imageWidth, imageHeight, settings, parent, onClick) :
				new ImageButton(windowName, pathToImage, dType, iType, imageWidth, imageHeight, settings, parent, onClickFunctionName, onClickFunctionModule);
		}
	}
}
