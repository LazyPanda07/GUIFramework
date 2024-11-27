#pragma once

#include "BaseListView.h"
#include "Interfaces/Components/ListViews/ITextListView.h"
#include "Interfaces/Localization/IMultipleTextLocalized.h"

namespace gui_framework
{
	/// @brief Base class for all list views with text items only
	class GUI_FRAMEWORK_API BaseTextListView : 
		public interfaces::IMultipleTextLocalized,
		public BaseListView,
		public interfaces::ITextListView
	{
	protected:
		virtual void updateLocalization(size_t index, std::wstring_view localizedText) override;

	public:
		BaseTextListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComposite* parent);

		/// @brief Used as key in creators
		/// @return typeid().hash_code()
		virtual size_t getHash() const override = 0;

		virtual json::JSONBuilder getStructure() const override;

		virtual LRESULT addTextItem(std::string_view localizationKey) final override;
		
		virtual LRESULT insertTextItem(std::string_view localizationKey, size_t index) final override;

		virtual LRESULT changeTextItem(std::string_view localizationKey, size_t index) final override;

		virtual ~BaseTextListView() = default;

		using interfaces::ITextListView::addTextItem;

		using interfaces::ITextListView::insertTextItem;

		using interfaces::ITextListView::changeTextItem;
	};
}
