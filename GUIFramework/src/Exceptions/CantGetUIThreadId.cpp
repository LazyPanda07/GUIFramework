#include "CantGetUIThreadId.h"

using namespace std;

namespace gui_framework
{
	namespace exceptions
	{
		CantGetUIThreadId::CantGetUIThreadId(string_view fileName, string_view methodName, int line) :
			BaseGUIFrameworkException("Can't get UI thread id", fileName, methodName, line)
		{

		}
	}
}
