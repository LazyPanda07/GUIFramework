#include "headers.h"
#include "ImageButtonCreator.h"

#include "Components/Buttons/ImageButton.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* ImageButtonCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			auto [text, pathToImage, imageWidth, imageHeight, type, onClick, onClickFunctionName, onClickFunctionModule] = any_cast<tuple<wstring, filesystem::path, uint16_t, uint16_t, ImageButton::drawingType, function<void()>, string, string>>(additionalData);
			
			return onClickFunctionName.empty() ?
				new ImageButton(windowName, pathToImage, type, imageWidth, imageHeight, settings.x, settings.y, parent, onClick, settings.width, settings.height) :
				new ImageButton(windowName, pathToImage, type, imageWidth, imageHeight, settings.x, settings.y, parent, onClickFunctionName, onClickFunctionModule, settings.width, settings.height);
		}
	}
}
