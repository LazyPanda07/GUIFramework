#include "pch.h"
#include "TabControl.h"

using namespace std;

namespace gui_framework
{
	TabControl::TabControl(const wstring& tabControlName, const utility::ComponentSettings& settings, BaseComponent* parent, uint16_t imagesWidth, uint16_t imagesHeight) :
		BaseComponent
		(
			wstring(standard_classes::tabControl),
			tabControlName,
			settings,
			parent
		),
		BaseResizableComponent
		(
			wstring(standard_classes::tabControl),
			tabControlName,
			settings,
			parent
		),
		BaseTabControl
		(
			tabControlName,
			settings,
			imagesWidth,
			imagesHeight,
			parent
		)
	{

	}
}
