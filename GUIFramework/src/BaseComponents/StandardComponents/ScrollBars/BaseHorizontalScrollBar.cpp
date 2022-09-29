#include "core.h"
#include "BaseHorizontalScrollBar.h"

#include "Styles/Components/ScrollBars/HorizontalScrollBarStyles.h"

using namespace std;

namespace gui_framework
{
	BaseHorizontalScrollBar::BaseHorizontalScrollBar(const wstring& scrollBarName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseScrollBar
		(
			scrollBarName,
			settings,
			styles::HorizontalScrollBarStyles(),
			parent
		)
	{

	}
}
