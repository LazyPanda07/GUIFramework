#include "headers.h"
#include "EditControl.h"

using namespace std;

namespace gui_framework
{
	EditControl::EditControl(const wstring& editControlName, int x, int y, BaseComponent* parent, uint16_t width, uint16_t height, bool isMultiLine) :
		BaseEditControl
		(
			editControlName,
			utility::ComponentSettings
			(
				x,
				y,
				width,
				height
			),
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
