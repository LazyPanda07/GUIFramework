#include "headers.h"
#include "RichEditAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		AdditionalCreationData<RichEdit>::AdditionalCreationData(const array<function<void(const wstring&)>, BaseRichEdit::urlDetectEventSize>& callbacks, uint64_t textLimitCount, bool isMultiLine) :
			callbacks(callbacks),
			textLimitCount(textLimitCount),
			isMultiLine(isMultiLine)
		{

		}

		AdditionalCreationData<RichEdit>::AdditionalCreationData(const array<pair<string, string>, BaseRichEdit::urlDetectEventSize>& callbacksFunctionNamesAndModules, uint64_t textLimitCount, bool isMultiLine) :
			callbacksFunctionNamesAndModules(callbacksFunctionNamesAndModules),
			textLimitCount(textLimitCount),
			isMultiLine(isMultiLine)
		{

		}

		any AdditionalCreationData<RichEdit>::getData() const
		{
			return make_any<tuple<array<function<void(const wstring&)>, BaseRichEdit::urlDetectEventSize>, array<pair<string, string>, BaseRichEdit::urlDetectEventSize>, uint64_t, bool>>(callbacks, callbacksFunctionNamesAndModules, textLimitCount, isMultiLine);
		}
	}
}
