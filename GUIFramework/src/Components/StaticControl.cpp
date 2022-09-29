#include "core.h"
#include "StaticControl.h"

using namespace std;

namespace gui_framework
{
	StaticControl::StaticControl(const wstring& staticControlName, const wstring& editControlText, const utility::ComponentSettings& settings, BaseComponent* parent) :
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
