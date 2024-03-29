#include "BaseVerticalScrollBar.h"

#include "Styles/Components/ScrollBars/VerticalScrollBarStyles.h"

using namespace std;

namespace gui_framework
{
	BaseVerticalScrollBar::BaseVerticalScrollBar(const wstring& scrollBarName, const utility::ComponentSettings& settings, BaseComposite* parent) :
		BaseScrollBar
		(
			scrollBarName,
			settings,
			styles::VerticalScrollBarStyles(),
			parent
		)
	{

	}
}
