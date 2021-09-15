#include "headers.h"
#include "ChildWindowAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		AdditionalCreationData<ChildWindow>::AdditionalCreationData(const wstring& className, const string& functionName) :
			className(className),
			functionName(functionName)
		{

		}

		any AdditionalCreationData<ChildWindow>::getData() const
		{
			return make_any<tuple<wstring, string>>(className, functionName);
		}
	}
}
