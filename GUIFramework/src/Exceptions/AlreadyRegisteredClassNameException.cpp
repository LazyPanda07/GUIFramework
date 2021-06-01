#include "pch.h"
#include "AlreadyRegisteredClassNameException.h"

using namespace std;

namespace gui_framework
{
	namespace exceptions
	{
		AlreadyRegisteredclassNameException::AlreadyRegisteredclassNameException() :
			BaseGUIFrameworkException(string(exception_messages::alreadyRegisteredClassName))
		{

		}
	}
}

