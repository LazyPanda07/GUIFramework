#pragma once

#include "core.h"
#include "BaseListView.h"
#include "Interfaces/Components/ListViews/IIconListView.h"

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
		BaseIconListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComposite* parent, utility::iconListViewType type, uint16_t iconsWidth, uint16_t iconsHeight, size_t count = standard_sizes::defaultImagesCount);

		/// @brief Not implemented
		/// @param red 
		/// @param green 
		/// @param blue 
		/// @exception NotImplemented Text color does not affects at list view with icon
		virtual void setTextColor(uint8_t red, uint8_t green, uint8_t blue) final override;

		/// @brief Used as key in creators
		/// @return typeid().hash_code()
		virtual size_t getHash() const override = 0;

		virtual json::JSONBuilder getStructure() const override;

		virtual ~BaseIconListView() = default;
	};
}
