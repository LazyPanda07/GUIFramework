#include "pch.h"
#include "ButtonAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		AdditionalCreationData<Button>::AdditionalCreationData(const wstring text, const function<LRESULT(WPARAM, LPARAM)>& onClick) :
			text(text),
			onClick(onClick)
		{

		}

		any AdditionalCreationData<Button>::getData() const
		{
			return make_any<tuple<wstring, function<LRESULT(WPARAM, LPARAM)>>>(text, onClick);
		}

		AdditionalCreationData<CheckBox>::AdditionalCreationData(const wstring text, const function<LRESULT(WPARAM, LPARAM)>& onCheck, const function<LRESULT(WPARAM, LPARAM)>& onClear, const function<LRESULT(WPARAM, LPARAM)>& onClick) :
			text(text),
			onCheck(onCheck),
			onClear(onClear),
			onClick(onClick)
		{

		}

		any AdditionalCreationData<CheckBox>::getData() const
		{
			return make_any<tuple<wstring, function<LRESULT(WPARAM, LPARAM)>, function<LRESULT(WPARAM, LPARAM)>, function<LRESULT(WPARAM, LPARAM)>>>(text, onCheck, onClear, onClick);
		}
	}
}
