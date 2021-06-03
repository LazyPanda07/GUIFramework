#include "pch.h"
#include "StandardEditControl.h"

using namespace std;

namespace gui_framework
{
	StandardEditControl::StandardEditControl(const wstring& editControlName, int x, int y, BaseComponent* parent, int width, int height) :
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
