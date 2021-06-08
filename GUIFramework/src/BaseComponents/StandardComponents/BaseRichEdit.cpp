#include "pch.h"
#include "BaseRichEdit.h"

using namespace std;

namespace gui_framework
{
	BaseRichEdit::BaseRichEdit(const wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseComponent
		(
			wstring(standard_classes::richEdit),
			windowName,
			settings,
			parent
		),
		IResizableComponent
		(
			handle,
			parent ? parent->getHandle() : nullptr
		),
		ITextOperations
		(
			handle
		)
	{

	}
}
