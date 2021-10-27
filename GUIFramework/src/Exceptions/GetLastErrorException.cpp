#include "headers.h"
#include "GetLastErrorException.h"

using namespace std;

namespace gui_framework
{
	namespace exceptions
	{
		GetLastErrorException::GetLastErrorException(DWORD errorCode, string_view fileName, string_view methodName, int line) :
			BaseGUIFrameworkException(format(R"(GetLastError returns "{}")"sv, errorCode), fileName, methodName, line)
		{

		}
	}
}
