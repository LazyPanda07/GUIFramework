#include "BaseGUIFrameworkException.h"

#include "Utility/Utility.h"

using namespace std;

namespace gui_framework
{
	namespace exceptions
	{
		BaseGUIFrameworkException::BaseGUIFrameworkException(const string& exceptionMessage, string_view fileName, string_view methodName, int line) :
			runtime_error(__utility::extendedException(exceptionMessage, fileName, methodName, line))
		{
			
		}
	}
}
