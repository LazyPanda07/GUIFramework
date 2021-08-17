#include "pch.h"
#include "GroupBox.h"

#include "Styles/Components/Buttons/RadioButtonStyles.h"

#include "Exceptions/CantFindFunctionFromModuleException.h"

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

	GroupBox::RadioButton::RadioButton(const wstring& radioButtonName, const wstring& radioButtonText, const utility::ComponentSettings& settings, BaseComponent* parent, const string& functionName, const string& moduleName) :
		BaseButton
		(
			radioButtonName,
			radioButtonText,
			settings,
			styles::RadioButtonStyles(),
			parent,
			functionName,
			moduleName
		)
	{

	}

	GroupBox::radioButtonData::radioButtonData() :
		x(0),
		y(0),
		width(0),
		height(0)
	{

	}

	GroupBox::radioButtonData::radioButtonData(const wstring& radioButtonName, const wstring& radioButtonText, const utility::ComponentSettings& settings, const function<void()>& onClick) :
		radioButtonName(radioButtonName),
		radioButtonText(radioButtonText),
		x(settings.x),
		y(settings.y),
		width(settings.width),
		height(settings.height),
		onClick(onClick)
	{

	}

	GroupBox::radioButtonData::radioButtonData(const wstring& radioButtonName, const wstring& radioButtonText, const utility::ComponentSettings& settings, const string& functionName, const string& moduleName) :
		radioButtonName(radioButtonName),
		radioButtonText(radioButtonText),
		x(settings.x),
		y(settings.y),
		width(settings.width),
		height(settings.height),
		functionName(functionName),
		moduleName(moduleName)
	{
		GUIFramework& instance = GUIFramework::get();
		const HMODULE& module = instance.getModules().at(moduleName);

		onClickSignature tem = reinterpret_cast<onClickSignature>(GetProcAddress(module, functionName.data()));

		if (!tem)
		{
			throw exceptions::CantFindFunctionFromModuleException(functionName, moduleName);
		}

		onClick = tem;
	}

	const string& GroupBox::getCreationType() const
	{
		return serialized_creation_type::groupBox;
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
		if (data.functionName.empty())
		{
			new RadioButton(data.radioButtonName, data.radioButtonText, utility::ComponentSettings(data.x, data.y, data.width, data.height), this, data.onClick);
		}
		else
		{
			new RadioButton(data.radioButtonName, data.radioButtonText, utility::ComponentSettings(data.x, data.y, data.width, data.height), this, data.functionName, data.moduleName);
		}
	}
}
