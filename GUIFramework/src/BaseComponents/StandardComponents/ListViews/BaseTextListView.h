#pragma once

#include "headers.h"
#include "BaseListView.h"
#include "Interfaces/Components/ListViews/ITextListView.h"

namespace gui_framework
{
	/// @brief Base class for all list views with text items only
	class GUI_FRAMEWORK_API BaseTextListView : 
		public BaseListView,
		public interfaces::ITextListView
	{
	public:
		BaseTextListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent);

		virtual json::JSONBuilder getStructure() const override;

		virtual ~BaseTextListView() = default;
	};
}
