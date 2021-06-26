#pragma once

#include "BaseListView.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API BaseTextListView : public BaseListView
	{
	public:
		BaseTextListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent);

		virtual ~BaseTextListView() = default;
	};
}
