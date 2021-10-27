#include "headers.h"
#include "CantFindCompositeFunctionException.h"

using namespace std;

namespace gui_framework
{
	namespace exceptions
	{
		CantFindCompositeFunctionException::CantFindCompositeFunctionException(const string& functionName, string_view fileName, string_view methodName, int line) :
			BaseGUIFrameworkException(format(R"%(Cant find "CREATE_DEFAULT_WINDOW_FUNCTION({})" macro)%"sv, functionName), fileName, methodName, line)
		{

		}
	}
}
