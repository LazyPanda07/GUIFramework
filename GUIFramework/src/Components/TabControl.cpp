#include "headers.h"
#include "TabControl.h"

using namespace std;

namespace gui_framework
{
	TabControl::TabControl(const wstring& tabControlName, const utility::ComponentSettings& settings, BaseComponent* parent, uint16_t imagesWidth, uint16_t imagesHeight) :
		BaseTabControl
		(
			tabControlName,
			settings,
			imagesWidth,
			imagesHeight,
			parent
		),
		IResizableComponent
		(
			handle,
			parent->getHandle()
		)
	{

	}

	size_t TabControl::getHash() const
	{
		return typeid(TabControl).hash_code();
	}

	json::JSONBuilder TabControl::getStructure() const
	{
		using json::utility::jsonObject;
		using json::utility::objectSmartPointer;

		json::JSONBuilder builder = BaseTabControl::getStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		return builder;
	}
}
