#include "pch.h"
#include "ButtonAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		AdditionalCreationData<Button>::AdditionalCreationData(const wstring text, const function<void()>& onClick) :
			text(text),
			onClick(onClick)
		{

		}

		any AdditionalCreationData<Button>::getData() const
		{
			return make_any<tuple<wstring, function<void()>>>(text, onClick);
		}

		AdditionalCreationData<CheckBox>::AdditionalCreationData(const wstring text, const function<void()>& onCheck, const function<void()>& onClear, const function<void()>& onClick) :
			text(text),
			onCheck(onCheck),
			onClear(onClear),
			onClick(onClick)
		{

		}

		any AdditionalCreationData<CheckBox>::getData() const
		{
			return make_any<tuple<wstring, function<void()>, function<void()>, function<void()>>>(text, onCheck, onClear, onClick);
		}
	}
}
