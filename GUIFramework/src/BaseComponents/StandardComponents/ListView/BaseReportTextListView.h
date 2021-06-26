#pragma once

#include "BaseReportListView.h"
#include "Interfaces/Components/ListView/ITextListView.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API BaseReportTextListView :
		public BaseReportListView,
		public interfaces::ITextListView
	{
	public:
		BaseReportTextListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent);

		virtual ~BaseReportTextListView() = default;
	};
}
