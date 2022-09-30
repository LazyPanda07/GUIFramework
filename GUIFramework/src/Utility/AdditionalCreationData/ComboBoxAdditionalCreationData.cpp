#include "Core.h"
#include "ComboBoxAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		AdditionalCreationData<DropDownComboBox>::AdditionalCreationData(const vector<wstring>& values, const function<void(BaseComboBox&)>& onSelectionChange) :
			values(values),
			onSelectionChange(onSelectionChange)
		{

		}

		AdditionalCreationData<DropDownComboBox>::AdditionalCreationData(const vector<wstring>& values, const string& functionName, const string& moduleName) :
			values(values),
			functionName(functionName),
			moduleName(moduleName)
		{
			
		}

		any AdditionalCreationData<DropDownComboBox>::getData() const
		{
			return make_any<tuple<vector<wstring>, function<void(BaseComboBox&)>, string, string>>(values, onSelectionChange, functionName, moduleName);
		}

		AdditionalCreationData<DropDownListComboBox>::AdditionalCreationData(const vector<wstring>& values, const function<void(BaseComboBox&)>& onSelectionChange) :
			values(values),
			onSelectionChange(onSelectionChange)
		{

		}

		AdditionalCreationData<DropDownListComboBox>::AdditionalCreationData(const vector<wstring>& values, const string& functionName, const string& moduleName) :
			values(values),
			functionName(functionName),
			moduleName(moduleName)
		{
			
		}

		any AdditionalCreationData<DropDownListComboBox>::getData() const
		{
			return make_any<tuple<vector<wstring>, function<void(BaseComboBox&)>, string, string>>(values, onSelectionChange, functionName, moduleName);
		}

		AdditionalCreationData<SimpleComboBox>::AdditionalCreationData(const vector<wstring>& values, const function<void(BaseComboBox&)>& onSelectionChange) :
			values(values),
			onSelectionChange(onSelectionChange)
		{

		}

		AdditionalCreationData<SimpleComboBox>::AdditionalCreationData(const vector<wstring>& values, const string& functionName, const string& moduleName) :
			values(values),
			functionName(functionName),
			moduleName(moduleName)
		{
			
		}

		any AdditionalCreationData<SimpleComboBox>::getData() const
		{
			return make_any<tuple<vector<wstring>, function<void(BaseComboBox&)>, string, string>>(values, onSelectionChange, functionName, moduleName);
		}
	}
}
