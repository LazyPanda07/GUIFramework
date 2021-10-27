#include "headers.h"
#include "SelectListException.h"

using namespace std;

namespace gui_framework
{
	namespace exceptions
	{
		SelectListException::SelectListException(const string& method, LRESULT errorCode, string_view fileName, string_view methodName, int line, string_view additionalDescription) :
			BaseGUIFrameworkException(format(R"(Exception in method "{}" with error code "{}". {})"sv, method, errorCode, additionalDescription), fileName, methodName, line)
		{

		}
	}
}
