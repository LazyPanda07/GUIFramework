#include "core.h"
#include "BaseVerticalAndHorizontalScrollBar.h"

#include "Styles/Components/ScrollBars/VerticalAndHorizontalScrollBarStyles.h"

using namespace std;

namespace gui_framework
{
	BaseVerticalAndHorizontalScrollBar::BaseVerticalAndHorizontalScrollBar(const wstring& scrollBarName, const utility::ComponentSettings& settings, BaseComposite* parent) :
		BaseScrollBar
		(
			scrollBarName,
			settings,
			styles::VerticalAndHorizontalScrollBarStyles(),
			parent
		)
	{

	}
}
