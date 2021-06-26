#pragma once

#include "BaseListListView.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API BaseListTextListView : public BaseListListView
	{
	public:
		BaseListTextListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent);

		virtual ~BaseListTextListView() = default;
	};
}
