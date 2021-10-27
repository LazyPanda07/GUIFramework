#include "headers.h"
#include "CantLoadModuleException.h"

using namespace std;

namespace gui_framework
{
	namespace exceptions
	{
		CantLoadModuleException::CantLoadModuleException(const string& moduleName, string_view fileName, string_view methodName, int line) :
			BaseGUIFrameworkException(format(R"(Can't load "{}" module or it's dependencies)"sv, moduleName), fileName, methodName, line)
		{

		}
	}
}
