#include "headers.h"
#include "BaseGUIFrameworkException.h"

using namespace std;

namespace gui_framework
{
	namespace exceptions
	{
		BaseGUIFrameworkException::BaseGUIFrameworkException(const string& exceptionMessage, string_view fileName, string_view methodName, int line) :
			runtime_error(format(R"({} in file "{}" in "{}" method on {} line)"sv, exceptionMessage, fileName.substr(fileName.rfind('\\') + 1), methodName, line))
		{
			
		}
	}
}
