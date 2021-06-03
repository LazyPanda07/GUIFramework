#include "pch.h"
#include "StandardStaticControl.h"

using namespace std;

namespace gui_framework
{
	StandardStaticControl::StandardStaticControl(const wstring& staticControlName, const wstring& editControlText, int x, int y, BaseComponent* parent, int width, int height) :
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