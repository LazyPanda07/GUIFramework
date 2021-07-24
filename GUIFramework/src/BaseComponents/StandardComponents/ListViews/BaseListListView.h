#pragma once

#include "pch.h"
#include "BaseListView.h"
#include "Styles/Components/ListViews/ListListViewStyles.h"

namespace gui_framework
{
	/// @brief Base class for all list views in list mode
	class GUI_FRAMEWORK_API BaseListListView : public BaseListView
	{
	public:
		BaseListListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, const styles::ListListViewStyles& styles, BaseComponent* parent);

		virtual ~BaseListListView() = default;
	};
}
