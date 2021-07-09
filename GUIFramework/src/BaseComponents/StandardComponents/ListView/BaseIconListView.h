#pragma once

#include "BaseListView.h"
#include "Interfaces/Components/ListView/IIconListView.h"

namespace gui_framework
{
	/// @brief Base class for all list views with icon items only
	class GUI_FRAMEWORK_API BaseIconListView : 
		public BaseListView,
		public interfaces::IIconListView
	{
	protected:
		utility::IconsHolder icons;

	public:
		BaseIconListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent, utility::iconListViewType type, uint16_t iconsWidth, uint16_t iconsHeight, size_t count = standard_sizes::defaultImagesCount);

		virtual ~BaseIconListView() = default;
	};
}
