#include "pch.h"
#include "BaseRichEdit.h"

#include "Styles/Components/DefaultRichEditStyles.h"

using namespace std;

namespace gui_framework
{
	LRESULT BaseRichEdit::windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		isUsed = false;

		if (message == WM_NOTIFY && this->getAutoURLDetect())
		{
			NMHDR* notification = reinterpret_cast<NMHDR*>(lparam);

			if (notification->code == EN_LINK)
			{
				ENLINK* ptrLink = reinterpret_cast<ENLINK*>(lparam);

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

	BaseRichEdit::BaseRichEdit(const wstring& richEditName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseComponent
		(
			wstring(standard_classes::richEdit),
			richEditName,
			settings,
			styles::DefaultRichEditStyles(),
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
		this->setText(L"");
	}

	void BaseRichEdit::addUrlDetectEvent(urlDetectEvent event, const function<void(const wstring&)>& eventCallback)
	{
		callbacks[event] = eventCallback;
	}

	void BaseRichEdit::removeUrlDetectEvent(urlDetectEvent event)
	{
		callbacks.erase(event);
	}

	LRESULT BaseRichEdit::findSubstring(const wstring& subStringToFind, bool isMatchCase)
	{
		FINDTEXTEXW findText;

		findText.chrg.cpMin = 0;
		findText.chrg.cpMax = -1;

		findText.lpstrText = subStringToFind.data();

		return SendMessageW(handle, EM_FINDTEXTEXW, NULL | FR_DOWN | (isMatchCase ? FR_MATCHCASE : NULL), reinterpret_cast<LPARAM>(&findText));
	}

	LRESULT BaseRichEdit::findString(const wstring& stringToFind, bool isMatchCase)
	{
		FINDTEXTEXW findText;

		findText.chrg.cpMin = 0;
		findText.chrg.cpMax = -1;

		findText.lpstrText = stringToFind.data();

		return SendMessageW(handle, EM_FINDTEXTEXW, FR_WHOLEWORD | FR_DOWN | (isMatchCase ? FR_MATCHCASE : NULL), reinterpret_cast<LPARAM>(&findText));
	}

	void BaseRichEdit::setAutoURLDetect(bool autoURLDetect)
	{
		if (autoURLDetect)
		{
			SendMessageW(handle, EM_SETEVENTMASK, NULL, SendMessageW(handle, EM_GETEVENTMASK, NULL, NULL) | ENM_LINK);

			SendMessageW(handle, EM_AUTOURLDETECT, AURL_ENABLEURL, NULL);
		}
		else
		{
			SendMessageW(handle, EM_SETEVENTMASK, NULL, SendMessageW(handle, EM_GETEVENTMASK, NULL, NULL) & ~ENM_LINK);

			SendMessageW(handle, EM_AUTOURLDETECT, NULL, NULL);
		}
	}

	void BaseRichEdit::setLimitText(uint64_t count)
	{
		SendMessageW(handle, EM_EXLIMITTEXT, NULL, count);
	}

	bool BaseRichEdit::getAutoURLDetect() const
	{
		return SendMessageW(handle, EM_GETAUTOURLDETECT, NULL, NULL);
	}

	wstring BaseRichEdit::getSelectedText() const
	{
		CHARRANGE range;

		SendMessageW(handle, EM_EXGETSEL, NULL, reinterpret_cast<LPARAM>(&range));

		return this->getText().substr(range.cpMin, static_cast<size_t>(range.cpMax) - range.cpMin);
	}

	void BaseRichEdit::setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		BaseComponent::setBackgroundColor(red, green, blue);

		SendMessageW(handle, EM_SETBKGNDCOLOR, NULL, static_cast<LPARAM>(backgroundColor));
	}

	void BaseRichEdit::setTextColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		BaseComponent::setTextColor(red, green, blue);

		CHARFORMAT2W textFormat;

		textFormat.cbSize = sizeof(CHARFORMAT2W);
		textFormat.dwMask = CFM_COLOR;
		textFormat.crTextColor = RGB(red, green, blue);
		textFormat.dwEffects = NULL;

		SendMessageW(handle, EM_SETCHARFORMAT, SCF_ALL, reinterpret_cast<LPARAM>(&textFormat));
	}
}
