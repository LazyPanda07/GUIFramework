#include "pch.h"
#include "SelectListException.h"

using namespace std;

namespace gui_framework
{
	namespace exceptions
	{
		SelectListException::SelectListException(const string& method, LRESULT errorCode, const string_view& additionalDescription) :
			BaseGUIFrameworkException(format("Exception in method {} with error code {}. {}", method, errorCode, additionalDescription))
		{

		}
	}
}
