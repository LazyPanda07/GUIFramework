#pragma once

#include "BaseComponents/StandardComponents/ListView/BaseListTextListView.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API ListTextListView : public BaseListTextListView
	{
	public:
		ListTextListView(const std::wstring& listViewName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent);

		~ListTextListView() = default;
	};
}