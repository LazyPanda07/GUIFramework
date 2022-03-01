#include "ICloseable.h"

using namespace std;

namespace gui_framework
{
	namespace interfaces
	{
		ICloseable::ICloseable(HWND closeableHandle) :
			closeableHandle(closeableHandle)
		{

		}

		bool ICloseable::close()
		{
			return DestroyWindow(closeableHandle);
		}
	}
}
