#pragma once

#include "headers.h"
#include "BaseComposites/BaseComposite.h"
#include "Interfaces/Components/IComponentVisibility.h"
#include "Interfaces/Components/ICloseable.h"

namespace gui_framework
{
	/// @brief Base class for all dialog boxes
	class GUI_FRAMEWORK_API BaseDialogBox : 
		public BaseComposite,
		public interfaces::IComponentVisibility,
		public interfaces::ICloseable
	{
	public:
		enum class messageBoxType
		{
			ok = MB_OK,
			okCancel,
			abortRetryIgnore,
			yesNoCancel,
			yesNo,
			retryCancel,
			cancelTryContinue
		};

		enum class messageBoxResponse
		{
			ok = IDOK,
			cancel,
			abort,
			retry,
			ignore,
			yes,
			no,
			tryAgain = IDTRYAGAIN,
			continueResponse
		};

	public:
		static messageBoxResponse createMessageBox(const std::wstring& text, const std::wstring& title, messageBoxType type, BaseComponent* parent = nullptr, bool helpButton = false);

	protected:
		bool isShowDialogUsed;

	public:
		/// @brief 
		/// @param moduleName Name of loaded resource module with icons
		/// @param smallIconResource Integer value from auto generated Visual Studio resources
		/// @param largeIconResource Integer value from auto generated Visual Studio resources
		BaseDialogBox(const std::wstring& className, const std::wstring& title, const utility::ComponentSettings& settings, const std::string& dialogBoxFunctionName = "", const std::string& moduleName = "", uint16_t smallIconResource = NULL, uint16_t largeIconResource = NULL);

		void showDialog();

		/// @brief Used as key in creators
		/// @return typeid().hash_code()
		virtual size_t getHash() const override = 0;

		virtual ~BaseDialogBox();
	};
}
