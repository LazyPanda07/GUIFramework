#pragma once

#include "BaseComposite.h"

namespace gui_framework
{
	class BaseDialogBox : virtual public BaseComposite
	{
	public:
		enum class messageBoxType
		{
			ok,
			okCancel,
			abortRetryIgnore,
			yesNoCancel,
			yesNo,
			retryCancel,
			cancelTryContinue
		};

		enum class messageBoxResponse
		{
			ok = 1,
			cancel,
			abort,
			retry,
			ignore,
			yes,
			no,
			tryAgain = 10,
			continueResponse
		};

	public:
		static messageBoxResponse createMessageBox(const std::wstring& text, const std::wstring& title, messageBoxType type, BaseComponent* parent = nullptr, bool helpButton = false);

	public:
		BaseDialogBox(const std::wstring& className, const std::wstring& title, const utility::ComponentSettings& settings, BaseComponent* parent = nullptr, const std::string& dialogBoxFunctionName = "");

		virtual void hide() const final;

		virtual void show() const final;

		virtual ~BaseDialogBox() = default;
	};
}
