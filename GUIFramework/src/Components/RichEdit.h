#pragma once

#include "BaseComponents/StandardComponents/BaseRichEdit.h"

namespace gui_framework
{
	class RichEdit : public BaseRichEdit
	{
	public:
		RichEdit(const std::wstring& richEditName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, bool isMultiLine);

		~RichEdit() = default;
	};
}
