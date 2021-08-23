#include "headers.h"
#include "ComboBoxAdditionalCreationData.h"

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

		AdditionalCreationData<DropDownListComboBox>::AdditionalCreationData(const vector<wstring>& values) :
			values(values)
		{

		}

		any AdditionalCreationData<DropDownListComboBox>::getData() const
		{
			return make_any<vector<wstring>>(values);
		}

		AdditionalCreationData<SimpleComboBox>::AdditionalCreationData(const vector<wstring>& values) :
			values(values)
		{

		}

		any AdditionalCreationData<SimpleComboBox>::getData() const
		{
			return make_any<vector<wstring>>(values);
		}
	}
}
