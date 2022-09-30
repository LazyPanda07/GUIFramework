#include "TabControl.h"

#include "BaseComposites/BaseComposite.h"

using namespace std;

namespace gui_framework
{
	TabControl::TabControl(const wstring& tabControlName, const utility::ComponentSettings& settings, BaseComposite* parent, uint16_t imagesWidth, uint16_t imagesHeight) :
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

		json::JSONBuilder builder = BaseTabControl::getStructure();
		jsonObject& current = get<jsonObject>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		return builder;
	}
}
