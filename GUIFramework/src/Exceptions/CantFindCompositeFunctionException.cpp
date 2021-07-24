#include "pch.h"
#include "CantFindCompositeFunctionException.h"

using namespace std;

namespace gui_framework
{
	namespace exceptions
	{
		CantFindCompositeFunctionException::CantFindCompositeFunctionException(const string& functionName) :
			BaseGUIFrameworkException(format("Cant find 'CREATE_DEFAULT_WINDOW_FUNCTION({})' macro", functionName))
		{

		}
	}
}
