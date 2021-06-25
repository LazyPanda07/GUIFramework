#pragma once

#include "BaseListView.h"

namespace gui_framework
{
	class BaseReportListView : public BaseListView
	{
	public:
		BaseReportListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent);

		virtual ~BaseReportListView() = default;
	};
}
