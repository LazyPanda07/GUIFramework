#include "headers.h"
#include "RichEditCreator.h"

#include "Components/RichEdit.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* RichEditCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			auto [callbacks, callbacksFunctionNamesAndModules, limitTextCount, isMultiLine] =
				any_cast<tuple<array<function<void(const wstring&)>, BaseRichEdit::urlDetectEventSize>, array<pair<string, string>, BaseRichEdit::urlDetectEventSize>, uint64_t, bool>>(additionalData);

			RichEdit* result = new RichEdit(windowName, settings, parent, isMultiLine);

			if (any_of(callbacks.begin(), callbacks.end(), [](const function<void(const wstring&)>& callback) { return callback; }) ||
				any_of(callbacksFunctionNamesAndModules.begin(), callbacksFunctionNamesAndModules.end(), [](const pair<string, string>& data) { return data.first.size(); }))
			{
				result->setAutoURLDetect(true);

				for (size_t i = 0; i < BaseRichEdit::urlDetectEventSize; i++)
				{
					switch (i)
					{
					case 0:
						if (callbacks[i])
						{
							result->addUrlDetectEvent(BaseRichEdit::urlDetectEvent::mouseMove, callbacks[i]);
						}
						else if (callbacksFunctionNamesAndModules[i].first.size())
						{
							result->addUrlDetectEvent(BaseRichEdit::urlDetectEvent::mouseMove, callbacksFunctionNamesAndModules[i].first, callbacksFunctionNamesAndModules[i].second);
						}

						break;

					case 1:
						if (callbacks[i])
						{
							result->addUrlDetectEvent(BaseRichEdit::urlDetectEvent::leftButtonDown, callbacks[i]);
						}
						else if (callbacksFunctionNamesAndModules[i].first.size())
						{
							result->addUrlDetectEvent(BaseRichEdit::urlDetectEvent::leftButtonDown, callbacksFunctionNamesAndModules[i].first, callbacksFunctionNamesAndModules[i].second);
						}

						break;

					case 2:
						if (callbacks[i])
						{
							result->addUrlDetectEvent(BaseRichEdit::urlDetectEvent::leftButtonUp, callbacks[i]);
						}
						else if (callbacksFunctionNamesAndModules[i].first.size())
						{
							result->addUrlDetectEvent(BaseRichEdit::urlDetectEvent::leftButtonUp, callbacksFunctionNamesAndModules[i].first, callbacksFunctionNamesAndModules[i].second);
						}

						break;

					case 3:
						if (callbacks[i])
						{
							result->addUrlDetectEvent(BaseRichEdit::urlDetectEvent::leftButtonDoubleClick, callbacks[i]);
						}
						else if (callbacksFunctionNamesAndModules[i].first.size())
						{
							result->addUrlDetectEvent(BaseRichEdit::urlDetectEvent::leftButtonDoubleClick, callbacksFunctionNamesAndModules[i].first, callbacksFunctionNamesAndModules[i].second);
						}

						break;

					case 4:
						if (callbacks[i])
						{
							result->addUrlDetectEvent(BaseRichEdit::urlDetectEvent::rightButtonDown, callbacks[i]);
						}
						else if (callbacksFunctionNamesAndModules[i].first.size())
						{
							result->addUrlDetectEvent(BaseRichEdit::urlDetectEvent::rightButtonDown, callbacksFunctionNamesAndModules[i].first, callbacksFunctionNamesAndModules[i].second);
						}

						break;

					case 5:
						if (callbacks[i])
						{
							result->addUrlDetectEvent(BaseRichEdit::urlDetectEvent::rightButtonUp, callbacks[i]);
						}
						else if (callbacksFunctionNamesAndModules[i].first.size())
						{
							result->addUrlDetectEvent(BaseRichEdit::urlDetectEvent::rightButtonUp, callbacksFunctionNamesAndModules[i].first, callbacksFunctionNamesAndModules[i].second);
						}

						break;

					case 6:
						if (callbacks[i])
						{
							result->addUrlDetectEvent(BaseRichEdit::urlDetectEvent::rightButtonDoubleClick, callbacks[i]);
						}
						else if (callbacksFunctionNamesAndModules[i].first.size())
						{
							result->addUrlDetectEvent(BaseRichEdit::urlDetectEvent::rightButtonDoubleClick, callbacksFunctionNamesAndModules[i].first, callbacksFunctionNamesAndModules[i].second);
						}

						break;

					case 7:
						if (callbacks[i])
						{
							result->addUrlDetectEvent(BaseRichEdit::urlDetectEvent::setCursor, callbacks[i]);
						}
						else if (callbacksFunctionNamesAndModules[i].first.size())
						{
							result->addUrlDetectEvent(BaseRichEdit::urlDetectEvent::setCursor, callbacksFunctionNamesAndModules[i].first, callbacksFunctionNamesAndModules[i].second);
						}

						break;

					default:
						break;
					}
				}
			}

			result->setLimitText(limitTextCount);

			return result;
		}
	}
}
