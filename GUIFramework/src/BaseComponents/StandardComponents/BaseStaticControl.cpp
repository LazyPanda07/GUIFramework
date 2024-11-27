#include "BaseStaticControl.h"

#include "Styles/Components/StaticControlStyles.h"

using namespace std;

namespace gui_framework
{
	void BaseStaticControl::updateLocalization(wstring_view localizedText)
	{
		ITextOperations::setText(localizedText);
	}

	BaseStaticControl::BaseStaticControl(const wstring& staticControlName, const wstring& staticControlText, const utility::ComponentSettings& settings, BaseComposite* parent) :
		BaseComponent
		(
			standard_classes::staticControl,
			staticControlName,
			settings,
			styles::StaticControlStyles(),
			parent
		),
		ITextOperations(handle, staticControlText)
	{
		this->removeBorder();
	}

	void BaseStaticControl::addBorder()
	{
		gui_framework::utility::appendStyle(handle, WS_BORDER);
	}

	void BaseStaticControl::removeBorder()
	{
		gui_framework::utility::removeStyle(handle, WS_BORDER);
	}

	void BaseStaticControl::setText(string_view localizationKey)
	{
		this->setLocalizationKey(localizationKey);

		ITextOperations::setText(localizationKey);
	}
}
