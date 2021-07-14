#pragma once

#include "BaseComponents/StandardComponents/ListViews/BaseTextListView.h"

namespace gui_framework
{
	/// @brief Standard list view with text items
	class GUI_FRAMEWORK_API TextListView : public BaseTextListView
	{
	public:
		TextListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent);

		~TextListView() = default;
	};
}
