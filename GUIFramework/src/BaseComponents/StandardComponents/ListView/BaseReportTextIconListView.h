#pragma once

#include "BaseReportListView.h"
#include "Interfaces/Components/ListView/ITextIconListView.h"

namespace gui_framework
{
	class BaseReportTextIconListView :
		public BaseReportListView,
		public interfaces::ITextIconListView
	{
	protected:
		utility::ImagesHolder images;

	public:
		BaseReportTextIconListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent, utility::iconListViewType type, uint16_t iconsWidth, uint16_t iconsHeight, size_t count = standard_sizes::defaultImagesCount);

		virtual ~BaseReportTextIconListView() = default;
	};
}
