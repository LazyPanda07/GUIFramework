#include "core.h"
#include "NotImplemented.h"

using namespace std;

namespace gui_framework
{
	namespace exceptions
	{
		NotImplemented::NotImplemented(string_view methodName, string_view className, string_view fileName, int line) :
			BaseGUIFrameworkException(format(exception_messages::notImplemented, methodName, className), fileName, methodName, line)
		{

		}
	}
}
