#pragma once

#include "BaseListListView.h"
#include "Interfaces/Components/ListView/IIconListView.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API BaseListIconListView :
		public BaseListListView,
		public interfaces::IIconListView
	{
	protected:
		utility::ImagesHolder images;

	public:
		BaseListIconListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent, utility::iconListViewType type, uint16_t iconsWidth, uint16_t iconsHeight, size_t count = standard_sizes::defaultImagesCount);

		virtual ~BaseListIconListView() = default;
	};
}
