#include "pch.h"
#include "BaseRichEdit.h"

using namespace std;

namespace gui_framework
{
	LRESULT BaseRichEdit::preWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		isUsed = false;

		if (message == WM_NOTIFY && this->getAutoURLDetect())
		{
			ENLINK* ptrLink = reinterpret_cast<ENLINK*>(lparam);

			if (ptrLink->nmhdr.code == EN_LINK)
			{
				auto callback = callbacks.find(static_cast<urlDetectEvent>(ptrLink->msg));

				if (callback != callbacks.end())
				{
					isUsed = true;

					callback->second
					(
						this->getText().substr
						(
							ptrLink->chrg.cpMin,
							static_cast<size_t>(ptrLink->chrg.cpMax) - ptrLink->chrg.cpMin
						)
					);

					return 0;
				}
			}
		}

		return -1;
	}

	BaseRichEdit::BaseRichEdit(const wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseComponent
		(
			wstring(standard_classes::richEdit),
			windowName,
			settings,
			parent
		),
		IResizableComponent
		(
			handle,
			parent ? parent->getHandle() : nullptr
		),
		ITextOperations(handle),
		callbacks(urlDetectEventSize)
	{

	}

	void BaseRichEdit::addUrlDetectEvent(urlDetectEvent event, const function<void(const wstring&)>& eventCallback)
	{
		callbacks[event] = eventCallback;
	}

	void BaseRichEdit::removeUrlDetectEvent(urlDetectEvent event)
	{
		callbacks.erase(event);
	}

	void BaseRichEdit::setAutoURLDetect(bool autoURLDetect)
	{
		autoURLDetect ?
			SendMessageW(handle, EM_AUTOURLDETECT, AURL_ENABLEURL, NULL) :
			SendMessageW(handle, EM_AUTOURLDETECT, NULL, NULL);
	}

	bool BaseRichEdit::getAutoURLDetect() const
	{
		return SendMessageW(handle, EM_GETAUTOURLDETECT, NULL, NULL);
	}
}
