#pragma once

#include "headers.h"
#include "BaseListListView.h"
#include "Interfaces/Components/ListViews/ITextListView.h"

namespace gui_framework
{
	/// @brief Base class for all list views in list mode with text items
	class GUI_FRAMEWORK_API BaseListTextListView : 
		public BaseListListView,
		public interfaces::ITextListView
	{
	public:
		BaseListTextListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent);

		/// @brief Used as key in creators
		/// @return typeid().hash_code()
		virtual size_t getHash() const override = 0;

		virtual json::JSONBuilder getStructure() const override;

		virtual ~BaseListTextListView() = default;
	};
}
