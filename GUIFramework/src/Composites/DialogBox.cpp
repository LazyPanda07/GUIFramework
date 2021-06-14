#include "pch.h"
#include "DialogBox.h"

using namespace std;

namespace gui_framework
{
	using DialogBoxBuilder = DialogBox::DialogBoxBuilder;

	DialogBoxBuilder::DialogBoxBuilder(const wstring& className, const wstring& dialogBoxName, int x, int y) :
		settings
		(
			NULL,
			x,
			y,
			NULL,
			NULL
		),
		className(className),
		dialogBoxName(dialogBoxName),
		parent(nullptr)
	{

	}

	void DialogBoxBuilder::clear()
	{
		settings = utility::ComponentSettings
			(
				NULL,
				settings.x,
				settings.y,
				settings.width,
				settings.height
			);

		className.clear();
		dialogBoxName.clear();
		functionName.clear();

		parent = nullptr;
	}

	void DialogBoxBuilder::addDialogBoxFunction(const string& functionName)
	{
		this->functionName = functionName;
	}

	void DialogBoxBuilder::addParent(BaseComposite* parent)
	{
		this->parent = parent;
	}

	DialogBox* DialogBoxBuilder::build() const
	{
		DialogBox* result = new DialogBox(className, dialogBoxName, settings, parent, functionName);

		return new DialogBox(className, dialogBoxName, settings, parent, functionName);
	}

	DialogBoxBuilder::builderComponentData::builderComponentData(uint16_t width, uint16_t height, alignment type) :
		width(width),
		height(height),
		type(type)
	{

	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	DialogBox::DialogBox(const wstring& className, const wstring& dialogBoxName, const utility::ComponentSettings& settings, BaseComponent* parent, const string& dialogBoxFunctionName) :
		BaseComposite
		(
			className,
			dialogBoxName,
			utility::ComponentSettings
			(
				settings.styles | WS_SYSMENU | WS_CAPTION,
				settings.x,
				settings.y,
				settings.width,
				settings.height,
				settings.id,
				settings.extendedStyles | WS_EX_DLGMODALFRAME
			),
			parent,
			dialogBoxFunctionName
		),
		BaseNonResizableComposite
		(
			className,
			dialogBoxName,
			utility::ComponentSettings
			(
				settings.styles | WS_SYSMENU | WS_CAPTION,
				settings.x,
				settings.y,
				settings.width,
				settings.height,
				settings.id,
				settings.extendedStyles | WS_EX_DLGMODALFRAME
			),
			parent,
			dialogBoxFunctionName
		),
		BaseDialogBox
		(
			className,
			dialogBoxName,
			utility::ComponentSettings
			(
				settings.styles | WS_SYSMENU | WS_CAPTION,
				settings.x,
				settings.y,
				settings.width,
				settings.height,
				settings.id,
				settings.extendedStyles | WS_EX_DLGMODALFRAME
			),
			parent,
			dialogBoxFunctionName
		)
	{

	}
}
