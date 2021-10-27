#include "BaseDeserializationException.h"

using namespace std;

namespace gui_framework
{
	namespace exceptions
	{
		namespace deserialization
		{
			BaseDeserializationException::BaseDeserializationException(const string& exceptionMessage, string_view fileName, string_view methodName, int line) :
				BaseGUIFrameworkException(exceptionMessage, fileName, methodName, line)
			{

			}
		}
	}
}
