#pragma once

#include "BaseReportListView.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API BaseReportTextListView : public BaseReportListView
	{
	public:
		BaseReportTextListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent);

		virtual ~BaseReportTextListView() = default;
	};
}
