#include "pch.h"
#include "CantFindSeparateWindowFunctionException.h"

using namespace std;

namespace gui_framework
{
	namespace exceptions
	{
		CantFindSeparateWindowFunctionException::CantFindSeparateWindowFunctionException(const string& functionName) :
			BaseGUIFrameworkException(format("Cant find '{}' function", functionName))
		{

		}
	}
}
