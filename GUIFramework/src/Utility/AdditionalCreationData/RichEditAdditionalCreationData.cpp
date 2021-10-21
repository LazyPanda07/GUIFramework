#include "headers.h"
#include "RichEditAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		AdditionalCreationData<RichEdit>::AdditionalCreationData(const array<function<void(const wstring&)>, BaseRichEdit::urlDetectEventSize>& callbacks, bool isMultiLine, uint64_t limitTextCount) :
			callbacks(callbacks),
			limitTextCount(limitTextCount),
			isMultiLine(isMultiLine)
		{

		}

		AdditionalCreationData<RichEdit>::AdditionalCreationData(const array<pair<string, string>, BaseRichEdit::urlDetectEventSize>& callbacksFunctionNamesAndModules, bool isMultiLine, uint64_t limitTextCount) :
			callbacksFunctionNamesAndModules(callbacksFunctionNamesAndModules),
			limitTextCount(limitTextCount),
			isMultiLine(isMultiLine)
		{

		}

		any AdditionalCreationData<RichEdit>::getData() const
		{
			return make_any<tuple<array<function<void(const wstring&)>, BaseRichEdit::urlDetectEventSize>, array<pair<string, string>, BaseRichEdit::urlDetectEventSize>, uint64_t, bool>>(callbacks, callbacksFunctionNamesAndModules, limitTextCount, isMultiLine);
		}
	}
}
