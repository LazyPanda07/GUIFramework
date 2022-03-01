#pragma once

#include "headers.h"
#include "BaseListListView.h"
#include "Interfaces/Components/ListViews/ITextIconListView.h"
#include "Interfaces/Localization/IMultipleTextLocalized.h"

namespace gui_framework
{
	/// @brief Base class for all list views in list mode with text and icon items
	class BaseListTextIconListView :
		public interfaces::IMultipleTextLocalized,
		public BaseListListView,
		public interfaces::ITextIconListView
	{
	protected:
		utility::IconsHolder icons;

	protected:
		virtual void updateLocalization(size_t index, const std::wstring& localizedText) override;

	public:
		BaseListTextIconListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent, utility::iconListViewType type, uint16_t iconsWidth, uint16_t iconsHeight, size_t count = standard_sizes::defaultImagesCount);

		/// @brief Used as key in creators
		/// @return typeid().hash_code()
		virtual size_t getHash() const override = 0;

		virtual json::JSONBuilder getStructure() const override;

		virtual LRESULT addTextIconItem(const std::string& localizationKey, const std::filesystem::path& pathToIcon) final override;

		virtual LRESULT insertTextIconItem(const std::string& localizationKey, const std::filesystem::path& pathToIcon, size_t index) final override;

		virtual LRESULT changeTextIconItem(const std::string& localizationKey, const std::filesystem::path& pathToIcon, size_t index) final override;

		virtual ~BaseListTextIconListView() = default;
	};
}
