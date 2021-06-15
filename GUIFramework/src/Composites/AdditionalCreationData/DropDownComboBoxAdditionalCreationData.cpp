#include "pch.h"
#include "DropDownComboBoxAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		AdditionalCreationData<DropDownComboBox>::AdditionalCreationData(const vector<wstring>& values) :
			values(values)
		{

		}

		any AdditionalCreationData<DropDownComboBox>::getData() const
		{
			return make_any<vector<wstring>>(values);
		}
	}
}
