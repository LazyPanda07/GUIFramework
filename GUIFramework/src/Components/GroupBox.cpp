#include "pch.h"
#include "GroupBox.h"

using namespace std;

namespace gui_framework
{
	GroupBox::RadioButton::RadioButton(const wstring& radioButtonName, const wstring& radioButtonText, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, const function<LRESULT(WPARAM, LPARAM)>& onClick) :
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

	GroupBox::GroupBox(const wstring& groupBoxName, const wstring& groupBoxText, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent) :
		BaseComponent
		(
			wstring(standard_classes::button),
			groupBoxName,
			utility::ComponentSettings
			(
				BS_GROUPBOX,
				x,
				y,
				width,
				height
			),
			parent
		),
		BaseButton
		(
			groupBoxName,
			groupBoxText,
			utility::ComponentSettings
			(
				BS_GROUPBOX,
				x,
				y,
				width,
				height
			),
			parent
		)
	{
		
	}

	void GroupBox::addRadioButton(const wstring& radioButtonName, const wstring& radioButtonText, int x, int y, uint16_t width, uint16_t height, const function<LRESULT(WPARAM, LPARAM)>& onClick)
	{
		buttons.emplace_back(new RadioButton(radioButtonName, radioButtonText, x, y, width, height, this, onClick));
	}
}
