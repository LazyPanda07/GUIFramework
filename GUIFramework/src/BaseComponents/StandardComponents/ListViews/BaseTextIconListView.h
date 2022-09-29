#pragma once

#include "core.h"
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
		virtual void updateLocalization(size_t index, const std::wstring& localizedText) override;

	protected:
		utility::IconsHolder icons;

	public:
		BaseTextIconListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent, utility::iconListViewType type, uint16_t iconsWidth, uint16_t iconsHeight, size_t count = standard_sizes::defaultImagesCount);

		/// @brief Used as key in creators
		/// @return typeid().hash_code()
		virtual size_t getHash() const override = 0;

		virtual json::JSONBuilder getStructure() const override;

		virtual LRESULT addTextIconItem(const std::string& localizationKey, const std::filesystem::path& pathToIcon) override final;

		virtual LRESULT insertTextIconItem(const std::string& localizationKey, const std::filesystem::path& pathToIcon, size_t index) override final;

		virtual LRESULT changeTextIconItem(const std::string& localizationKey, const std::filesystem::path& pathToIcon, size_t index) override final;

		virtual ~BaseTextIconListView() = default;

		using interfaces::ITextIconListView::addTextIconItem;

		using interfaces::ITextIconListView::insertTextIconItem;

		using interfaces::ITextIconListView::changeTextIconItem;
	};
}
