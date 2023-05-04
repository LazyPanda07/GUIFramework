#include "EditControl.h"

#include "BaseComposites/BaseComposite.h"

using namespace std;

namespace gui_framework
{
	EditControl::EditControl(const wstring& editControlName, const utility::ComponentSettings& settings, BaseComposite* parent, bool isMultiLine) :
		BaseEditControl
		(
			editControlName,
			settings,
			parent,
			isMultiLine
		),
		IResizableComponent
		(
			handle,
			parent->getHandle()
		)
	{

	}

	size_t EditControl::getHash() const
	{
		return typeid(EditControl).hash_code();
	}
}
