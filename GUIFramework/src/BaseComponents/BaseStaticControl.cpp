#include "pch.h"
#include "BaseStaticControl.h"

using namespace std;

namespace gui_framework
{
	BaseStaticControl::BaseStaticControl(const wstring& staticControlName, const wstring& staticControlText, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseComponent
		(
			wstring(standard_classes::editControl),
			staticControlName,
			settings,
			parent
		),
		ITextOperations(handle)
	{
		this->setText(staticControlText);
	}
}
