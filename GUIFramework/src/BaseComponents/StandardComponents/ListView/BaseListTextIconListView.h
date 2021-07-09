#pragma once

#include "BaseListListView.h"
#include "Interfaces/Components/ListView/ITextIconListView.h"

namespace gui_framework
{
	/// @brief Base class for all list views in list mode with text and icon items
	class BaseListTextIconListView :
		public BaseListListView,
		public interfaces::ITextIconListView
	{
	protected:
		utility::IconsHolder icons;

	public:
		BaseListTextIconListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent, utility::iconListViewType type, uint16_t iconsWidth, uint16_t iconsHeight, size_t count = standard_sizes::defaultImagesCount);

		virtual ~BaseListTextIconListView() = default;
	};
}
