#include "pch.h"
#include "GetLastErrorException.h"

using namespace std;

namespace gui_framework
{
	namespace exceptions
	{
		GetLastErrorException::GetLastErrorException(DWORD errorCode) :
			BaseGUIFrameworkException(format(R"(GetLastError returns "{}")", errorCode))
		{

		}
	}
}
