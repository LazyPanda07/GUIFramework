#include "headers.h"
#include "INonResizableComponent.h"

#include "Exceptions/NotImplemented.h"

using namespace std;

namespace gui_framework
{
	namespace interfaces
	{
		INonResizableComponent::INonResizableComponent(HWND nonResizableHandle) :
			 nonResizableHandle(nonResizableHandle)
		{
			utility::removeStyle(nonResizableHandle, WS_THICKFRAME);

			utility::removeStyle(nonResizableHandle, WS_MAXIMIZEBOX);
		}

		void INonResizableComponent::resize(uint16_t width, uint16_t height)
		{
			__utility::throwNotImplementedException(__FUNCTION__, "INonResizableComponent"sv);
		}
	}
}
