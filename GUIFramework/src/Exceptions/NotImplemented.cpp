#include "headers.h"
#include "NotImplemented.h"

using namespace std;

namespace gui_framework
{
	namespace exceptions
	{
		NotImplemented::NotImplemented(string_view methodName, string_view className) :
			BaseGUIFrameworkException(format(exception_messages::notImplemented, methodName, className))
		{

		}
	}
}
