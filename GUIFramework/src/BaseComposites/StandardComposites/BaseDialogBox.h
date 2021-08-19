#pragma once

#include "pch.h"
#include "BaseComposites/BaseComposite.h"

namespace gui_framework
{
	/// @brief Base class for all dialog boxes
	class GUI_FRAMEWORK_API BaseDialogBox : public BaseComposite
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

	protected:
		virtual const std::string& getCreationType() const override;

	public:
		/// @brief 
		/// @param moduleName Name of loaded resource module with icons
		/// @param smallIconResource Integer value from auto generated Visual Studio resources
		/// @param largeIconResource Integer value from auto generated Visual Studio resources
		BaseDialogBox(const std::wstring& className, const std::wstring& title, const utility::ComponentSettings& settings, BaseComponent* parent = nullptr, const std::string& dialogBoxFunctionName = "", const std::string& moduleName = "", uint16_t smallIconResource = NULL, uint16_t largeIconResource = NULL);

		virtual void hide() const final;

		virtual void show() const final;

		virtual ~BaseDialogBox() = default;
	};
}
