#include "pch.h"
#include "SeparateWindowAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		AdditionalCreationData<SeparateWindow>::AdditionalCreationData(const wstring& className, const string& functionName) :
			className(className),
			functionName(functionName)
		{

		}

		any AdditionalCreationData<SeparateWindow>::getData() const
		{
			return make_any<tuple<wstring, string>>(className, functionName);
		}
	}
}
