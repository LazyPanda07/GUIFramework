#include "core.h"
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
				new Button(windowName, text, settings, parent, onClick) :
				new Button(windowName, text, settings, parent, onClickFunctionName, onClickFunctionModule);
		}
	}
}
