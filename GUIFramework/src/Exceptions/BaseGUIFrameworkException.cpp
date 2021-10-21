#include "headers.h"
#include "BaseGUIFrameworkException.h"

using namespace std;

namespace gui_framework
{
	namespace exceptions
	{
		BaseGUIFrameworkException::BaseGUIFrameworkException(const string& exceptionMessage) :
			runtime_error(exceptionMessage)
		{

		}
	}
}
