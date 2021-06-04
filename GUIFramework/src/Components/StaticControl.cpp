#include "pch.h"
#include "StaticControl.h"

using namespace std;

namespace gui_framework
{
	StaticControl::StaticControl(const wstring& staticControlName, const wstring& editControlText, int x, int y, BaseComponent* parent, int width, int height) :
		BaseResizableComponent
		(
			wstring(standard_classes::staticControl),
			editControlText,
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
		BaseStaticControl
		(
			staticControlName,
			editControlText,
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
