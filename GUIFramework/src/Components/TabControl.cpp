#include "pch.h"
#include "TabControl.h"

using namespace std;

namespace gui_framework
{
	TabControl::TabControl(const wstring& tabControlName, const utility::ComponentSettings& settings, BaseComponent* parent, uint16_t imagesWidth, uint16_t imagesHeight) :
		BaseTabControl
		(
			tabControlName,
			settings,
			imagesWidth,
			imagesHeight,
			parent
		),
		IResizableComponent
		(
			handle,
			parent->getHandle()
		)
	{

	}
}
