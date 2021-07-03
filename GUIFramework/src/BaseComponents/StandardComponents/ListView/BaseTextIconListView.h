#pragma once

#include "BaseListView.h"
#include "Interfaces/Components/ListView/ITextIconListView.h"

namespace gui_framework
{
	class BaseTextIconListView : 
		public BaseListView,
		public interfaces::ITextIconListView
	{
	protected:
		utility::IconsHolder icons;

	public:
		BaseTextIconListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent, utility::iconListViewType type, uint16_t iconsWidth, uint16_t iconsHeight, size_t count = standard_sizes::defaultImagesCount);

		virtual ~BaseTextIconListView() = default;
	};
}
