#include "pch.h"
#include "EditControl.h"

using namespace std;

namespace gui_framework
{
	EditControl::EditControl(const wstring& editControlName, int x, int y, BaseComponent* parent, int width, int height) :
		BaseComponent
		(
			wstring(standard_classes::button),
			editControlName,
			utility::ComponentSettings
			(
				NULL,
				x,
				y,
				width,
				height
			),
			parent
		),
		BaseResizableComponent
		(
			wstring(standard_classes::editControl),
			editControlName,
			utility::ComponentSettings
			(
				WS_BORDER,
				x,
				y,
				width,
				height
			),
			parent
		),
		BaseEditControl
		(
			editControlName,
			utility::ComponentSettings
			(
				WS_BORDER,
				x,
				y,
				width,
				height
			),
			parent
		)
	{

	}
}
