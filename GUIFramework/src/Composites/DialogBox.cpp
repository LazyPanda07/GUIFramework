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
			0,
			0
		),
		className(className),
		dialogBoxName(dialogBoxName),
		parent(nullptr)
	{

	}

	void DialogBoxBuilder::clear()
	{
		(*this) = DialogBoxBuilder(className, dialogBoxName, settings.x, settings.y);
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
		GUIFramework& reference = GUIFramework::get();

		for (const auto& i : components)
		{
			reference.getCreators().at(i.typeHash)->create
			(
				i.componentName,
				utility::ComponentSettings
				(
					NULL,
					i.offsets.left,
					i.offsets.top,
					i.width,
					i.height
				),
				i.additionalData,
				result
			);
		}

		return result;
	}

	DialogBoxBuilder::builderComponentData::builderComponentData(const wstring& componentName, const wstring& text, RECT&& offsets, size_t typeHash, uint16_t width, uint16_t height, alignment type, any&& additionalData) :
		componentName(componentName),
		text(text),
		offsets(move(offsets)),
		typeHash(typeHash),		
		width(width),
		height(height),
		type(type),
		additionalData(move(additionalData))
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
