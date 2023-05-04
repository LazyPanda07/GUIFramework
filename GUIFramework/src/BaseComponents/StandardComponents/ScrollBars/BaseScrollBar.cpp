#include "BaseScrollBar.h"

using namespace std;

namespace gui_framework
{
	BaseScrollBar::BaseScrollBar(const wstring& scrollBarName, const utility::ComponentSettings& settings, const styles::ScrollBarStyles& styles, BaseComposite* parent) :
		BaseComponent
		(
			standard_classes::scrollBar,
			scrollBarName,
			settings,
			styles,
			parent
		)
	{

	}
}
