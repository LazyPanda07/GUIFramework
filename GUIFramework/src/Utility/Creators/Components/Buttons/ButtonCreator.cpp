#include "headers.h"
#include "ButtonCreator.h"

#include "Components/Buttons/Button.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* ButtonCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			auto [text, onClick, onClickFunctionName, onClickFunctionModule] = any_cast<tuple<wstring, function<void()>, string, string>>(additionalData);

			return onClickFunctionName.empty() ?
				new Button(windowName, text, settings.x, settings.y, parent, onClick, settings.width, settings.height) :
				new Button(windowName, text, settings.x, settings.y, parent, onClickFunctionName, onClickFunctionModule, settings.width, settings.height);
		}
	}
}
