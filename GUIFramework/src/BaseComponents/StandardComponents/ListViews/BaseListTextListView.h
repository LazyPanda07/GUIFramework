#pragma once

#include "headers.h"
#include "BaseListListView.h"
#include "Interfaces/Components/ListViews/ITextListView.h"

namespace gui_framework
{
	/// @brief Base class for all list views in list mode with text items
	class GUI_FRAMEWORK_API BaseListTextListView : 
		public interfaces::IMultipleTextLocalized,
		public BaseListListView,
		public interfaces::ITextListView
	{
	private:
		virtual void updateLocalization(size_t index, const std::wstring& localizedText) override;

	public:
		BaseListTextListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent);

		/// @brief Used as key in creators
		/// @return typeid().hash_code()
		virtual size_t getHash() const override = 0;

		virtual json::JSONBuilder getStructure() const override;

		virtual LRESULT addTextItem(const std::string& localizationKey) final override;

		virtual LRESULT insertTextItem(const std::string& localizationKey, size_t index) final override;

		virtual LRESULT changeTextItem(const std::string& localizationKey, size_t index) final override;

		virtual ~BaseListTextListView() = default;
	};
}
