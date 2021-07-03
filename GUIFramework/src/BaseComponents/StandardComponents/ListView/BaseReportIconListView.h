#pragma once

#include "BaseReportListView.h"
#include "Interfaces/Components/ListView/IIconListView.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API BaseReportIconListView :
		public BaseReportListView,
		public interfaces::IIconListView
	{
	protected:
		utility::IconsHolder icons;

	public:
		BaseReportIconListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent, utility::iconListViewType type, uint16_t iconsWidth, uint16_t iconsHeight, size_t count = standard_sizes::defaultImagesCount);

		virtual ~BaseReportIconListView() = default;
	};
}
