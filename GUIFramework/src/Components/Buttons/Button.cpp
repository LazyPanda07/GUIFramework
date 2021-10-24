#include "headers.h"
#include "Button.h"

#include "Styles/Components/Buttons/DefaultButtonStyles.h"

using namespace std;

namespace gui_framework
{
	Button::Button(const wstring& buttonName, const wstring& buttonText, const utility::ComponentSettings& settings, BaseComponent* parent, const function<void()>& onClick) :
		BaseButton
		(
			buttonName,
			buttonText,
			settings,
			styles::DefaultButtonStyles(),
			parent,
			onClick
		),
		IResizableComponent
		(
			handle,
			parent->getHandle()
		)	
	{

	}

	Button::Button(const wstring& buttonName, const wstring& buttonText, const utility::ComponentSettings& settings, BaseComponent* parent, const string& functionName, const string& moduleName) :
		BaseButton
		(
			buttonName,
			buttonText,
			settings,
			styles::DefaultButtonStyles(),
			parent,
			functionName,
			moduleName
		),
		IResizableComponent
		(
			handle,
			parent->getHandle()
		)
	{

	}

	size_t Button::getHash() const
	{
		return typeid(Button).hash_code();
	}
}
