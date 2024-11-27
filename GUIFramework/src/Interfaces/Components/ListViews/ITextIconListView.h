#pragma once

#include "IBaseListViewOperations.h"
#include "Holders/LoadableHolders/IconsHolder.h"

namespace gui_framework
{
	namespace interfaces
	{
		/// @brief Provides adding text and icon items for list views
		class GUI_FRAMEWORK_API ITextIconListView : public IBaseListViewOperations
		{
		private:
			void onRemove(size_t index) final override;

			LVITEMW makeItem(std::wstring_view text, const std::filesystem::path& pathToIcon, size_t index);

		private:
			utility::IconsHolder& icons;
			std::unordered_map<size_t, size_t> textData;

		public:
			ITextIconListView(HWND handle, utility::IconsHolder& icons);

			virtual LRESULT addTextIconItem(std::wstring_view text, const std::filesystem::path& pathToIcon);

			virtual LRESULT addTextIconItem(std::string_view localizationKey, const std::filesystem::path& pathToIcon);

			virtual LRESULT insertTextIconItem(std::wstring_view text, const std::filesystem::path& pathToIcon, size_t index);

			virtual LRESULT insertTextIconItem(std::string_view localizationKey, const std::filesystem::path& pathToIcon, size_t index);

			virtual LRESULT changeTextIconItem(std::wstring_view text, const std::filesystem::path& pathToIcon, size_t index);

			virtual LRESULT changeTextIconItem(std::string_view localizationKey, const std::filesystem::path& pathToIcon, size_t index);

			/// @brief 
			/// @param index 
			/// @return Item text - icon index - path to icon
			virtual std::tuple<std::wstring, uint16_t, std::filesystem::path> getTextIconItem(size_t index) const;

			virtual ~ITextIconListView() = default;
		};
	}
}
