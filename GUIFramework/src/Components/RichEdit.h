#pragma once

#include "BaseComponents/StandardComponents/BaseRichEdit.h"

namespace gui_framework
{
	/// @brief Standard rich edit control
	class GUI_FRAMEWORK_API RichEdit : public BaseRichEdit
	{
	public:
		RichEdit(const std::wstring& richEditName, const utility::ComponentSettings& settings, BaseComposite* parent, bool isMultiLine = false);

		size_t getHash() const override;

		json::JSONBuilder getStructure() const override;

		~RichEdit() = default;
	};
}
