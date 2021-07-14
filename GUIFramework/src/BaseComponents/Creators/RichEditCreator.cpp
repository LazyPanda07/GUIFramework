#include "pch.h"
#include "RichEditCreator.h"

#include "Components/RichEdit.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* RichEditCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			auto [callbacks, textLimitCount, isMultiLine] = any_cast<tuple<vector<pair<BaseRichEdit::urlDetectEvent, function<void(const wstring&)>>>, uint64_t, bool>>(additionalData);

			RichEdit* richEdit = new RichEdit(windowName, utility::ComponentSettings(settings.x, settings.y, settings.width, settings.height), parent, isMultiLine);

			if (callbacks.size())
			{
				richEdit->setAutoURLDetect(true);

				for (const auto& [event, callback] : callbacks)
				{
					richEdit->addUrlDetectEvent(event, callback);
				}
			}

			richEdit->setLimitText(textLimitCount);

			return richEdit;
		}
	}
}
