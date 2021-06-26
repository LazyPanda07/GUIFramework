#pragma once

#include "BaseListView.h"
#include "Utility/ImagesHolder.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API BaseIconListView : public BaseListView
	{
	protected:
		utility::ImagesHolder images;

	public:
		BaseIconListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent, utility::iconListViewType type, uint16_t iconsWidth, uint16_t iconsHeight, size_t count = standard_sizes::defaultImagesCount);

		virtual ~BaseIconListView() = default;
	};
}
