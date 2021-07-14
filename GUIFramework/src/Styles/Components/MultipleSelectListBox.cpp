#include "pch.h"
#include "MultipleSelectListBox.h"

using namespace std;

namespace gui_framework
{
	namespace styles
	{
		MultipleSelectListBox::MultipleSelectListBox()
		{
			this->appendStyle(LBS_MULTIPLESEL);
		}
	}
}
