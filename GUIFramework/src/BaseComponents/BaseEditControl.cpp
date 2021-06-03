#include "pch.h"
#include "BaseEditControl.h"

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
			parent
		),
		ITextOperations(handle)
	{
		this->setText(L"");
	}
}
