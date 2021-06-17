#pragma once

#include "BaseComponents/StandardComponents/BaseRichEdit.h"

namespace gui_framework
{
	/// @brief Standard rich edit control
	class GUI_FRAMEWORK_API RichEdit : public BaseRichEdit
	{
	public:
		RichEdit(const std::wstring& richEditName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, bool isMultiLine = false);

		~RichEdit() = default;
	};
}
