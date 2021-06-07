#include "pch.h"
#include "ComboBoxException.h"

using namespace std;

namespace gui_framework
{
	namespace exceptions
	{
		ComboBoxException::ComboBoxException(const string& method, LRESULT errorCode, const string_view& additionalDescription) :
			BaseGUIFrameworkException(format("Exception in method {} with error code {}. {}", method, errorCode, additionalDescription))
		{

		}
	}
}
