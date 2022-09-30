#include "DialogBox.h"

#include "GUIFramework.h"

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

	DialogBox* DialogBoxBuilder::build() const
	{
		DialogBox* result = new DialogBox(className, dialogBoxName, settings, functionName, moduleName, smallIconResource, largeIconResource);
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
				xPosition = (settings.width - i.settings.width) / 2;

				break;
			case gui_framework::DialogBox::DialogBoxBuilder::alignment::right:
				xPosition = settings.width - i.settings.width - i.offsets.right;

				break;
			}

			const_cast<builderComponentData&>(i).settings.x = xPosition;
			const_cast<builderComponentData&>(i).settings.y = currentTopOffset;

			reference.getCreators().at(i.typeHash)->create
			(
				i.componentName,
				i.settings,
				i.additionalData,
				result
			);

			currentTopOffset += static_cast<uint16_t>(i.settings.height + i.offsets.bottom);
		}

		return result;
	}

	DialogBoxBuilder::builderComponentData::builderComponentData(const wstring& componentName, const interfaces::IStyles& styles, RECT&& offsets, size_t typeHash, uint16_t width, uint16_t height, alignment type, any&& additionalData) :
		componentName(componentName),
		offsets(move(offsets)),
		typeHash(typeHash),
		type(type),
		additionalData(move(additionalData))
	{
		settings.width = width;
		settings.height = height;
		settings.styles = styles;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	DialogBox::DialogBox(const wstring& className, const wstring& dialogBoxName, const utility::ComponentSettings& settings, const string& dialogBoxFunctionName, const string& moduleName, uint16_t smallIconResource, uint16_t largeIconResource) :
		BaseDialogBox
		(
			className,
			dialogBoxName,
			settings,
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

	size_t DialogBox::getHash() const
	{
		return typeid(DialogBox).hash_code();
	}
}
