#include "pch.h"
#include "BaseDialogBox.h"

#include "Styles/Composites/DialogBoxStyles.h"

using namespace std;

namespace gui_framework
{
	BaseDialogBox::messageBoxResponse BaseDialogBox::createMessageBox(const wstring& text, const wstring& title, messageBoxType type, BaseComponent* parent, bool helpButton)
	{
		return static_cast<messageBoxResponse>(MessageBoxW(parent ? parent->getHandle() : nullptr, text.data(), title.data(), static_cast<UINT>(type) | (helpButton ? MB_HELP : NULL)));
	}

	const string& BaseDialogBox::getCreationType() const
	{
		return serialized_creation_type::baseDialogBox;
	}

	BaseDialogBox::BaseDialogBox(const wstring& className, const wstring& title, const utility::ComponentSettings& settings, BaseComponent* parent, const string& dialogBoxFunctionName, const string& moduleName, uint16_t smallIconResource, uint16_t largeIconResource) :
		BaseComposite
		(
			className,
			title,
			settings,
			styles::DialogBoxStyles(),
			parent,
			dialogBoxFunctionName,
			moduleName,
			smallIconResource,
			largeIconResource
		)
	{
		this->hide();
	}

	void BaseDialogBox::hide() const
	{
		ShowWindow(handle, SW_HIDE);
	}

	void BaseDialogBox::show() const
	{
		ShowWindow(handle, SW_SHOW);
	}
}
