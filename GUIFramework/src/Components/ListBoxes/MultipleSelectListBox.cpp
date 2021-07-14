#include "pch.h"
#include "MultipleSelectListBox.h"

using namespace std;

namespace gui_framework
{
	MultipleSelectListBox::MultipleSelectListBox(const wstring& listBoxName, const utility::ComponentSettings& settings, BaseComponent* parent, bool isSorting) :
		BaseMultipleSelectListBox
		(
			listBoxName,
			settings,
			parent
		)
	{
		if (isSorting)
		{
			utility::appendStyle(handle, LBS_SORT);
		}
	}
}
