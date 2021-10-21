#include "headers.h"
#include "BaseRichEdit.h"

#include "Styles/Components/DefaultRichEditStyles.h"

#include "Exceptions/CantFindFunctionFromModuleException.h"

using namespace std;

namespace gui_framework
{
	void BaseRichEdit::addCallback(urlDetectEvent event, const function<void(const wstring&)>& callback, const string& functionName, const string& moduleName)
	{
		if (event == urlDetectEvent::setCursor)
		{
			callbacks[7] = callback;

			callbacksFunctionNamesAndModules[7] = make_pair(functionName, moduleName);
		}
		else
		{
			callbacks[static_cast<size_t>(event) % urlDetectEventSize] = callback;

			callbacksFunctionNamesAndModules[static_cast<size_t>(event) % urlDetectEventSize] = make_pair(functionName, moduleName);
		}
	}

	LRESULT BaseRichEdit::windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		isUsed = false;

		if (message == WM_NOTIFY && this->getAutoURLDetect())
		{
			NMHDR* notification = reinterpret_cast<NMHDR*>(lparam);

			if (notification->code == EN_LINK)
			{
				ENLINK* ptrLink = reinterpret_cast<ENLINK*>(lparam);

				const function<void(const wstring&)>& callback = this->getCallback(static_cast<urlDetectEvent>(ptrLink->msg));

				if (callback)
				{
					isUsed = true;

					callback
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

	BaseRichEdit::BaseRichEdit(const wstring& richEditName, const utility::ComponentSettings& settings, BaseComponent* parent, bool isMultiLine) :
		BaseComponent
		(
			standard_classes::richEdit,
			richEditName,
			settings,
			styles::DefaultRichEditStyles(isMultiLine),
			parent
		),
		IResizableComponent
		(
			handle,
			parent ? parent->getHandle() : nullptr
		),
		ITextOperations(handle),
		isMultiLine(isMultiLine),
		limitTextCount(0)
	{
		this->setText(L"");

		ranges::for_each(callbacks, [](function<void(const wstring&)>& callback) { callback = nullptr; });

		ranges::for_each(callbacksFunctionNamesAndModules, [](pair<string, string>& data) { data = make_pair(""s, ""s); });
	}

	void BaseRichEdit::addUrlDetectEvent(urlDetectEvent event, const function<void(const wstring&)>& eventCallback)
	{
		this->addCallback(event, eventCallback, ""s, ""s);
	}

	void BaseRichEdit::addUrlDetectEvent(urlDetectEvent event, const string& functionName, const string& moduleName)
	{
		GUIFramework& instance = GUIFramework::get();
		const HMODULE& module = instance.getModules().at(moduleName);

		richEditCallbackSignature tem = reinterpret_cast<richEditCallbackSignature>(GetProcAddress(module, functionName.data()));

		if (!tem)
		{
			throw exceptions::CantFindFunctionFromModuleException(functionName, moduleName);
		}

		this->addCallback(event, tem, functionName, moduleName);
	}

	void BaseRichEdit::removeUrlDetectEvent(urlDetectEvent event)
	{
		if (event == urlDetectEvent::setCursor)
		{
			callbacks[7] = nullptr;

			callbacksFunctionNamesAndModules[7] = make_pair(""s, ""s);
		}
		else
		{
			callbacks[static_cast<size_t>(event) % urlDetectEventSize] = nullptr;

			callbacksFunctionNamesAndModules[static_cast<size_t>(event) % urlDetectEventSize] = make_pair(""s, ""s);
		}
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
		limitTextCount = count;

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

	const function<void(const wstring&)>& BaseRichEdit::getCallback(urlDetectEvent event) const
	{
		if (event == urlDetectEvent::setCursor)
		{
			return callbacks[7];
		}

		return callbacks[static_cast<size_t>(event) % urlDetectEventSize];
	}

	bool BaseRichEdit::getIsMultiLine() const
	{
		return isMultiLine;
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

	json::JSONBuilder BaseRichEdit::getStructure() const
	{
		using json::utility::objectSmartPointer;
		using json::utility::jsonObject;

		pair<string, string> emptyPair = make_pair(""s, ""s);
		json::JSONBuilder builder = BaseComponent::getStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);
		vector<objectSmartPointer<jsonObject>> jsonCallbacks;
		const auto& modulesPaths = GUIFramework::get().getModulesPaths();

		current->data.push_back({ "isMultiLine"s, isMultiLine });

		current->data.push_back({ "limitTextCount"s, limitTextCount });

		for (size_t i = 0; i < callbacksFunctionNamesAndModules.size(); i++)
		{
			if (callbacksFunctionNamesAndModules[i] == emptyPair)
			{
				continue;
			}

			objectSmartPointer<jsonObject> object = json::utility::make_object<jsonObject>();

			object->data.push_back({ "callbackType"s, static_cast<uint64_t>(i) });

			object->data.push_back({ "callbackName"s, callbacksFunctionNamesAndModules[i].first });

			object->data.push_back({ "callbackModule"s, modulesPaths.at(callbacksFunctionNamesAndModules[i].second) });

			json::utility::appendArray(move(object), jsonCallbacks);
		}

		current->data.push_back({ "callbacks"s, move(jsonCallbacks) });

		return builder;
	}
}
