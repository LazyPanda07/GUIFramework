#include "IComponentVisibility.h"

using namespace std;

namespace gui_framework
{
	namespace interfaces
	{
		IComponentVisibility::IComponentVisibility(HWND componentVisibilityHandle) :
			componentVisibilityHandle(componentVisibilityHandle)
		{

		}

		void IComponentVisibility::show() const
		{
			ShowWindow(componentVisibilityHandle, SW_SHOW);

			SetFocus(componentVisibilityHandle);
		}

		void IComponentVisibility::hide() const
		{
			ShowWindow(componentVisibilityHandle, SW_HIDE);
		}
	}
}
