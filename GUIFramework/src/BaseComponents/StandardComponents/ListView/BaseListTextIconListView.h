#pragma once

#include "BaseListListView.h"
#include "Interfaces/Components/ListView/ITextIconListView.h"

namespace gui_framework
{
	class BaseListTextIconListView :
		public BaseListListView,
		public interfaces::ITextIconListView
	{
	protected:
		utility::ImagesHolder icons;

	public:
		BaseListTextIconListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent, utility::iconListViewType type, uint16_t iconsWidth, uint16_t iconsHeight, size_t count = standard_sizes::defaultImagesCount);

		virtual ~BaseListTextIconListView() = default;
	};
}
