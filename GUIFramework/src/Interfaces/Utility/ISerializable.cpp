#include "ISerializable.h"

using namespace std;

namespace gui_framework
{
	namespace interfaces
	{
		ostream& operator << (ostream& outputStream, const ISerializable& serializable) 
		{
			return outputStream << serializable.getStructure();
		}
	}
}
