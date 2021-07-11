#include "pch.h"
#include "GroupBox.h"

using namespace std;

namespace gui_framework
{
	GroupBox::RadioButton::RadioButton(const wstring& radioButtonName, const wstring& radioButtonText, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, const function<void()>& onClick) :
		BaseComponent
		(
			wstring(standard_classes::button),
			radioButtonName,
			utility::ComponentSettings
			(
				BS_AUTORADIOBUTTON,
				x,
				y,
				width,
				height
			),
			parent
		),
		BaseButton
		(
			radioButtonName,
			radioButtonText,
			utility::ComponentSettings
			(
				BS_AUTORADIOBUTTON,
				x,
				y,
				width,
				height
			),
			parent,
			onClick
		)
	{

	}

	GroupBox::radioButtonData::radioButtonData(const wstring& radioButtonName, const wstring& radioButtonText, int x, int y, uint16_t width, uint16_t height, const function<void()>& onClick) :
		radioButtonName(radioButtonName),
		radioButtonText(radioButtonText),
		x(x),
		y(y),
		width(width),
		height(height),
		onClick(onClick)
	{

	}

	GroupBox::GroupBox(const wstring& groupBoxClassName, const wstring& groupBoxName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, const string& groupBoxFunctionName) :
		BaseComposite
		(
			groupBoxClassName,
			groupBoxName,
			utility::ComponentSettings
			(
				NULL,
				x,
				y,
				width,
				height
			),
			parent,
			groupBoxFunctionName
		)
	{
		
	}

	void GroupBox::addRadioButton(const radioButtonData& data)
	{
		new RadioButton(data.radioButtonName, data.radioButtonText, data.x, data.y, data.width, data.height, this, data.onClick);
	}
}
