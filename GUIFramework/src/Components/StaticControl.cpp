#include "headers.h"
#include "StaticControl.h"

using namespace std;

namespace gui_framework
{
	StaticControl::StaticControl(const wstring& staticControlName, const wstring& editControlText, int x, int y, BaseComponent* parent, uint16_t width, uint16_t height) :
		BaseStaticControl
		(
			staticControlName,
			editControlText,
			utility::ComponentSettings
			(
				x,
				y,
				width,
				height
			),
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
