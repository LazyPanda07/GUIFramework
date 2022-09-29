#include "core.h"
#include "GroupBoxAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		AdditionalCreationData<GroupBox>::AdditionalCreationData(const wstring& groupBoxClassName, const string& groupBoxFunctionName, const vector<GroupBox::radioButtonData>& data) : 
			groupBoxClassName(groupBoxClassName),
			groupBoxFunctionName(groupBoxFunctionName),
			data(data)
		{

		}

		any AdditionalCreationData<GroupBox>::getData() const
		{
			return make_any<tuple<wstring, string, vector<GroupBox::radioButtonData>>>(groupBoxClassName, groupBoxFunctionName, data);
		}
	}
}
