#include "headers.h"
#include "NotImplemented.h"

using namespace std;

namespace gui_framework
{
	namespace exceptions
	{
		NotImplemented::NotImplemented(const string& methodName, const string& className) :
			BaseGUIFrameworkException(format(exception_messages::notImplemented, methodName, className))
		{

		}
	}
}
