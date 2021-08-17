#include "pch.h"
#include "GroupBox.h"

#include "Styles/Components/Buttons/RadioButtonStyles.h"

using namespace std;

namespace gui_framework
{
	GroupBox::RadioButton::RadioButton(const wstring& radioButtonName, const wstring& radioButtonText, const utility::ComponentSettings& settings, BaseComponent* parent, const function<void()>& onClick) :
		BaseButton
		(
			radioButtonName,
			radioButtonText,
			settings,
			styles::RadioButtonStyles(),
			parent,
			onClick
		)
	{

	}

	GroupBox::radioButtonData::radioButtonData(const wstring& radioButtonName, const wstring& radioButtonText, const utility::ComponentSettings& settings, const function<void()>& onClick) :
		radioButtonName(radioButtonName),
		radioButtonText(radioButtonText),
		x(x),
		y(y),
		width(width),
		height(height),
		onClick(onClick)
	{

	}

	string GroupBox::getCreationType() const
	{
		return "GroupBox";
	}

	GroupBox::GroupBox(const wstring& groupBoxClassName, const wstring& groupBoxName, const utility::ComponentSettings& settings, BaseComponent* parent, const string& groupBoxFunctionName) :
		BaseComposite
		(
			groupBoxClassName,
			groupBoxName,
			settings,
			styles::DefaultStyles(),
			parent,
			groupBoxFunctionName
		)
	{
		
	}

	void GroupBox::addRadioButton(const radioButtonData& data)
	{
		new RadioButton(data.radioButtonName, data.radioButtonText, utility::ComponentSettings(data.x, data.y, data.width, data.height), this, data.onClick);
	}

	json::JSONBuilder GroupBox::getStructure() const
	{
		using json::utility::jsonObject;
		using json::utility::objectSmartPointer;

		json::JSONBuilder builder = BaseComponent::getStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		return builder;
	}
}
