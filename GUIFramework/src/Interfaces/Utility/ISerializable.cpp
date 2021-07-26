#include "pch.h"
#include "ISerializable.h"

using namespace std;

namespace gui_framework
{
	namespace interfaces
	{
		ISerializable::ISerializable() :
			codepage(GetACP())
		{

		}

		void ISerializable::setCodepage(uint32_t codepage)
		{
			this->codepage = codepage;
		}

		uint32_t ISerializable::getCodepage() const
		{
			return codepage;
		}

		ostream& operator << (ostream& outputStream, const ISerializable& serializable) 
		{
			return outputStream << serializable.getStructure();
		}
	}
}
