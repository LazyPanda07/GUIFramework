#include "headers.h"
#include "RichEditAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		AdditionalCreationData<RichEdit>::AdditionalCreationData(const vector<pair<BaseRichEdit::urlDetectEvent, function<void(const wstring&)>>>& callbacks, uint64_t textLimitCount, bool isMultiLine) :
			callbacks(callbacks),
			textLimitCount(textLimitCount),
			isMultiLine(isMultiLine)
		{

		}

		any AdditionalCreationData<RichEdit>::getData() const
		{
			return make_any<tuple<vector<pair<BaseRichEdit::urlDetectEvent, function<void(const wstring&)>>>, uint64_t, bool>>(callbacks, textLimitCount, isMultiLine);
		}
	}
}
