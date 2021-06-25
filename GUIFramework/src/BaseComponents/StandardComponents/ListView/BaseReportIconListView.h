#pragma once

#include "BaseReportListView.h"
#include "Utility/ImagesHolder.h"

namespace gui_framework
{
	class BaseReportIconListView : public BaseReportListView
	{
	protected:
		utility::ImagesHolder images;

	public:
		BaseReportIconListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent, utility::iconListViewType type, uint16_t iconsWidth, uint16_t iconsHeight, size_t count = standard_sizes::defaultImagesCount);

		virtual ~BaseReportIconListView() = default;
	};
}
