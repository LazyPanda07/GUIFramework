#include "BaseEditControl.h"

#include "Styles/Components/EditControlStyles.h"
#include "Exceptions/GetLastErrorException.h"

using namespace std;

namespace gui_framework
{
	void BaseEditControl::updateLocalization(wstring_view localizedText)
	{
		this->setPlaceholder(localizedText);
	}

	BaseEditControl::BaseEditControl(const std::wstring& editControlName, const utility::ComponentSettings& settings, BaseComposite* parent, bool isMultiLine) :
		BaseComponent
		(
			standard_classes::editControl,
			editControlName,
			settings,
			styles::EditControlStyles(isMultiLine),
			parent
		),
		ITextOperations(handle)
	{
		ITextOperations::setText(L"");
	}

	bool BaseEditControl::setPlaceholder(std::wstring_view placeholder)
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

	json::JSONBuilder BaseEditControl::getStructure() const
	{
		using json::utility::jsonObject;

		json::JSONBuilder builder = BaseComponent::getStructure();
		uint32_t codepage = ISerializable::getCodepage();

		get<jsonObject>(builder[utility::to_string(windowName, codepage)]).data.push_back({ "placeholder"s, utility::to_string(placeholder, codepage) });

		return builder;
	}

	void BaseEditControl::setText(string_view localizationKey)
	{
		this->setLocalizationKey(localizationKey);

		ITextOperations::setText(localizationKey);
	}
}
