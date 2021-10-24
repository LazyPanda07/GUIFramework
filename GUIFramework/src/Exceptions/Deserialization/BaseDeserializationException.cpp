#include "BaseDeserializationException.h"

using namespace std;

namespace gui_framework
{
	namespace exceptions
	{
		namespace deserialization
		{
			BaseDeserializationException::BaseDeserializationException(const string& exceptionMessage) :
				BaseGUIFrameworkException(exceptionMessage)
			{

			}
		}
	}
}
