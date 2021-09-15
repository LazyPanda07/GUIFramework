#pragma once

#include "headers.h"
#include "BaseListView.h"
#include "Interfaces/Components/ListViews/ITextIconListView.h"

namespace gui_framework
{
	/// @brief Base class for all list views with text and icon items
	class BaseTextIconListView : 
		public BaseListView,
		public interfaces::ITextIconListView
	{
	protected:
		utility::IconsHolder icons;

	public:
		BaseTextIconListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent, utility::iconListViewType type, uint16_t iconsWidth, uint16_t iconsHeight, size_t count = standard_sizes::defaultImagesCount);

		/// @brief Used as key in creators
		/// @return typeid().hash_code()
		virtual size_t getHash() const override = 0;

		virtual json::JSONBuilder getStructure() const override;

		virtual ~BaseTextIconListView() = default;
	};
}
