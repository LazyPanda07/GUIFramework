#include "pch.h"
#include "BaseEditControl.h"

#include "Styles/Components/EditControlStyles.h"
#include "Exceptions/GetLastErrorException.h"

using namespace std;

namespace gui_framework
{
	json::JSONBuilder BaseEditControl::getStructure() const
	{
		using json::utility::jsonObject;
		using json::utility::objectSmartPointer;

		json::JSONBuilder builder = BaseComponent::getStructure();
		uint32_t codepage = ISerializable::getCodepage();

		get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, codepage)])->data.push_back({ "placeholder"s, utility::to_string(placeholder, codepage) });

		return builder;
	}

	BaseEditControl::BaseEditControl(const std::wstring& editControlName, const utility::ComponentSettings& settings, BaseComponent* parent, bool isMultiLine) :
		BaseComponent
		(
			wstring(standard_classes::editControl),
			editControlName,
			settings,
			styles::EditControlStyles(isMultiLine),
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
