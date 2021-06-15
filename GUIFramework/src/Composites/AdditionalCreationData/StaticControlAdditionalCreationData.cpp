#include "pch.h"
#include "StaticControlAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		AdditionalCreationData<StaticControl>::AdditionalCreationData(const wstring& text) :
			text(text)
		{

		}

		any AdditionalCreationData<StaticControl>::getData() const
		{
			return make_any<wstring>(text);
		}
	}
}
