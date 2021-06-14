#include "pch.h"
#include "DialogBox.h"

#pragma push_macro("DialogBox")
#undef DialogBox

using namespace std;

namespace gui_framework
{
	DialogBox::DialogBox(const wstring& className, const wstring& dialogBoxName, const utility::ComponentSettings& settings, BaseComponent* parent, const string& dialogBoxFunctionName) :
		BaseComposite
		(
			className,
			dialogBoxName,
			utility::ComponentSettings
			(
				settings.styles | WS_SYSMENU | WS_CAPTION,
				settings.x,
				settings.y,
				settings.width,
				settings.height,
				settings.id,
				settings.extendedStyles | WS_EX_DLGMODALFRAME
			),
			parent,
			dialogBoxFunctionName
		),
		BaseNonResizableComposite
		(
			className,
			dialogBoxName,
			utility::ComponentSettings
			(
				settings.styles | WS_SYSMENU | WS_CAPTION,
				settings.x,
				settings.y,
				settings.width,
				settings.height,
				settings.id,
				settings.extendedStyles | WS_EX_DLGMODALFRAME
			),
			parent,
			dialogBoxFunctionName
		),
		BaseDialogBox
		(
			className,
			dialogBoxName,
			utility::ComponentSettings
			(
				settings.styles | WS_SYSMENU | WS_CAPTION,
				settings.x,
				settings.y,
				settings.width,
				settings.height,
				settings.id,
				settings.extendedStyles | WS_EX_DLGMODALFRAME
			),
			parent,
			dialogBoxFunctionName
		)
	{

	}
}

#pragma pop_macro("DialogBox")
