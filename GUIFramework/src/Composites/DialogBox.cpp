#include "headers.h"
#include "DialogBox.h"

using namespace std;

namespace gui_framework
{
	using DialogBoxBuilder = DialogBox::DialogBoxBuilder;

	DialogBoxBuilder::DialogBoxBuilder(const wstring& className, const wstring& dialogBoxName, int x, int y, const string& dialogBoxFunctionName, const string& moduleName, uint16_t smallIconResource, uint16_t largeIconResource) :
		settings
		(
			x,
			y,
			standard_sizes::dialogBoxBuilderMinWidth,
			standard_sizes::dialogBoxBuilderMinHeight
		),
		className(className),
		dialogBoxName(dialogBoxName),
		parent(nullptr),
		functionName(dialogBoxFunctionName),
		moduleName(moduleName),
		smallIconResource(smallIconResource),
		largeIconResource(largeIconResource)
	{

	}

	DialogBoxBuilder& DialogBoxBuilder::clear()
	{
		(*this) = DialogBoxBuilder(className, dialogBoxName, settings.x, settings.y, functionName);

		return *this;
	}

	DialogBoxBuilder& DialogBoxBuilder::addParent(BaseComposite* parent)
	{
		this->parent = parent;

		return *this;
	}

	DialogBox* DialogBoxBuilder::build() const
	{
		DialogBox* result = new DialogBox(className, dialogBoxName, settings, parent, functionName, moduleName, smallIconResource, largeIconResource);
		GUIFramework& reference = GUIFramework::get();
		uint16_t currentTopOffset = 0;

		for (const builderComponentData& i : components)
		{
			currentTopOffset += static_cast<uint16_t>(i.offsets.top);
			int xPosition = 0;

			switch (i.type)
			{
			case gui_framework::DialogBox::DialogBoxBuilder::alignment::left:
				xPosition = i.offsets.left;

				break;
			case gui_framework::DialogBox::DialogBoxBuilder::alignment::center:
				xPosition = (settings.width - i.width) / 2;

				break;
			case gui_framework::DialogBox::DialogBoxBuilder::alignment::right:
				xPosition = settings.width - i.width - i.offsets.right;

				break;
			}

			reference.getCreators().at(i.typeHash)->create
			(
				i.componentName,
				utility::ComponentSettings
				(
					xPosition,
					currentTopOffset,
					i.width,
					i.height
				),
				i.additionalData,
				result
			);

			currentTopOffset += static_cast<uint16_t>(i.height + i.offsets.bottom);
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

	const string& DialogBox::getCreationType() const
	{
		return serialized_creation_type::dialogBox;
	}

	DialogBox::DialogBox(const wstring& className, const wstring& dialogBoxName, const utility::ComponentSettings& settings, BaseComponent* parent, const string& dialogBoxFunctionName, const string& moduleName, uint16_t smallIconResource, uint16_t largeIconResource) :
		BaseDialogBox
		(
			className,
			dialogBoxName,
			settings,
			parent,
			dialogBoxFunctionName,
			moduleName,
			smallIconResource,
			largeIconResource
		),
		INonResizableComponent
		(
			handle
		)
	{

	}
}
