#include "pch.h"
#include "BaseEditControl.h"

#include "Styles/DefaultStyles.h"
#include "Exceptions/GetLastErrorException.h"

using namespace std;

namespace gui_framework
{
	BaseEditControl::BaseEditControl(const std::wstring& editControlName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseComponent
		(
			wstring(standard_classes::editControl),
			editControlName,
			settings,
			styles::DefaultStyles(),
			parent
		),
		ITextOperations(handle)
	{
		this->setText(L"");
	}

	bool BaseEditControl::setPlaceholder(const std::wstring& placeholder)
	{
		bool result = SendMessageW(handle, EM_SETCUEBANNER, false, reinterpret_cast<LPARAM>(placeholder.data()));

		if (result)
		{
			this->placeholder = placeholder;
		}

		return result;
	}

	const wstring& BaseEditControl::getPlaceholder() const
	{
		return placeholder;
	}
}
