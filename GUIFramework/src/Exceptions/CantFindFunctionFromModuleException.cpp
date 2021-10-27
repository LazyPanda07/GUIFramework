#include "headers.h"
#include "CantFindFunctionFromModuleException.h"

using namespace std;

namespace gui_framework
{
	namespace exceptions
	{
		CantFindFunctionFromModuleException::CantFindFunctionFromModuleException(const string& functionName, const string& moduleName, string_view fileName, string_view methodName, int line) :
			BaseGUIFrameworkException(format(R"(Can't find function "{}" in module "{}")"sv, functionName, moduleName), fileName, methodName, line)
		{

		}
	}
}
