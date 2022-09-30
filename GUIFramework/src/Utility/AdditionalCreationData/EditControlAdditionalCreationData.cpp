#include "EditControlAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		AdditionalCreationData<EditControl>::AdditionalCreationData(const wstring& placeholder) :
			placeholder(placeholder)
		{

		}

		any AdditionalCreationData<EditControl>::getData() const
		{
			return make_any<wstring>(placeholder);
		}
	}
}
