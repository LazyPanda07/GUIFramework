#pragma once

#include "BaseListView.h"
#include "Interfaces/Components/ListViews/ITextIconListView.h"
#include "Interfaces/Localization/IMultipleTextLocalized.h"

namespace gui_framework
{
	/// @brief Base class for all list views with text and icon items
	class BaseTextIconListView : 
		public interfaces::IMultipleTextLocalized,
		public BaseListView,
		public interfaces::ITextIconListView
	{
	protected:
		virtual void updateLocalization(size_t index, std::wstring_view localizedText) override;

	protected:
		utility::IconsHolder icons;

	public:
		BaseTextIconListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComposite* parent, utility::iconListViewType type, uint16_t iconsWidth, uint16_t iconsHeight, size_t count = standard_sizes::defaultImagesCount);

		/// @brief Used as key in creators
		/// @return typeid().hash_code()
		virtual size_t getHash() const override = 0;

		virtual json::JSONBuilder getStructure() const override;

		virtual LRESULT addTextIconItem(std::string_view localizationKey, const std::filesystem::path& pathToIcon) override final;

		virtual LRESULT insertTextIconItem(std::string_view localizationKey, const std::filesystem::path& pathToIcon, size_t index) override final;

		virtual LRESULT changeTextIconItem(std::string_view localizationKey, const std::filesystem::path& pathToIcon, size_t index) override final;

		virtual ~BaseTextIconListView() = default;

		using interfaces::ITextIconListView::addTextIconItem;

		using interfaces::ITextIconListView::insertTextIconItem;

		using interfaces::ITextIconListView::changeTextIconItem;
	};
}
