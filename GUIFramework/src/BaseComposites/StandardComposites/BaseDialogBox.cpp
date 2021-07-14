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

	BaseDialogBox::BaseDialogBox(const wstring& className, const wstring& title, const utility::ComponentSettings& settings, BaseComponent* parent, const string& dialogBoxFunctionName) :
		BaseComposite
		(
			className,
			title,
			settings,
			styles::DialogBoxStyles(),
			parent,
			dialogBoxFunctionName
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
