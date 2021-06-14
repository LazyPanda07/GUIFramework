#pragma once

#include "BaseComposites/BaseDialogBox.h"
#include "BaseComposites/BaseNonResizableComposite.h"

#pragma push_macro("DialogBox")
#undef DialogBox

namespace gui_framework
{
	class DialogBox : 
		public BaseNonResizableComposite,
		public BaseDialogBox
	{
	public:
		DialogBox(const std::wstring& className, const std::wstring& dialogBoxName, const utility::ComponentSettings& settings, BaseComponent* parent = nullptr, const std::string& dialogBoxFunctionName = "");

		~DialogBox() = default;
	};
}

#pragma pop_macro("DialogBox")
