#include "StaticControl.h"

#include "BaseComposites/BaseComposite.h"

using namespace std;

namespace gui_framework
{
	StaticControl::StaticControl(const wstring& staticControlName, const wstring& editControlText, const utility::ComponentSettings& settings, BaseComposite* parent) :
		BaseStaticControl
		(
			staticControlName,
			editControlText,
			settings,
			parent
		),
		IResizableComponent
		(
			handle,
			parent->getHandle()
		)
	{

	}

	size_t StaticControl::getHash() const
	{
		return typeid(StaticControl).hash_code();
	}
}
