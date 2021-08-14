#include "pch.h"
#include "BaseStaticControl.h"

#include "Styles/Components/StaticControlStyles.h"

using namespace std;

namespace gui_framework
{
	BaseStaticControl::BaseStaticControl(const wstring& staticControlName, const wstring& staticControlText, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseComponent
		(
			wstring(standard_classes::staticControl),
			staticControlName,
			settings,
			styles::StaticControlStyles(),
			parent
		),
		ITextOperations(handle)
	{
		this->setText(staticControlText);
	}
}
