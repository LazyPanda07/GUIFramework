#include "pch.h"
#include "CantFindFunctionFromModuleException.h"

using namespace std;

namespace gui_framework
{
	namespace exceptions
	{
		CantFindFunctionFromModuleException::CantFindFunctionFromModuleException(const string& functionName, const string& moduleName) :
			BaseGUIFrameworkException(format(R"(Can't find function "{}" in module "{}")", functionName, moduleName))
		{

		}
	}
}
