#include "headers.h"
#include "CantLoadModuleException.h"

using namespace std;

namespace gui_framework
{
	namespace exceptions
	{
		CantLoadModuleException::CantLoadModuleException(const string& moduleName) :
			BaseGUIFrameworkException(format(R"(Can't load "{}" module or it's dependencies)", moduleName))
		{

		}
	}
}
