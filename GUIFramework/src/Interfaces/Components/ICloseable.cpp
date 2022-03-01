#include "ICloseable.h"

#include "BaseComposites/BaseComposite.h"

using namespace std;

namespace gui_framework
{
	namespace interfaces
	{
		ICloseable::ICloseable(HWND closeableHandle) :
			closeableHandle(closeableHandle)
		{

		}

		bool ICloseable::close(int exitCode)
		{
			dynamic_cast<BaseComposite*>(this)->setExitCode(exitCode);

			return DestroyWindow(closeableHandle);
		}
	}
}
