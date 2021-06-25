#pragma once

#include "BaseListListView.h"
#include "Utility/ImagesHolder.h"

namespace gui_framework
{
	class BaseListIconListView : public BaseListListView
	{
	protected:
		utility::ImagesHolder images;

	public:
		BaseListIconListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent, utility::iconListViewType type, uint16_t iconsWidth, uint16_t iconsHeight, size_t count = standard_sizes::defaultImagesCount);

		virtual ~BaseListIconListView() = default;
	};
}
