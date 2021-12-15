#include "headers.h"
#include "BaseStaticControl.h"

#include "Styles/Components/StaticControlStyles.h"

using namespace std;

namespace gui_framework
{
	void BaseStaticControl::updateLocalization(const wstring& localizedText)
	{
		this->setText(localizedText);
	}

	BaseStaticControl::BaseStaticControl(const wstring& staticControlName, const wstring& staticControlText, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseComponent
		(
			standard_classes::staticControl,
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
