#pragma once

#include "BaseListView.h"
#include "Interfaces/Components/ListView/IIconListView.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API BaseIconListView : 
		public BaseListView,
		public interfaces::IIconListView
	{
	protected:
		utility::ImagesHolder icons;

	public:
		BaseIconListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent, utility::iconListViewType type, uint16_t iconsWidth, uint16_t iconsHeight, size_t count = standard_sizes::defaultImagesCount);

		virtual ~BaseIconListView() = default;
	};
}
