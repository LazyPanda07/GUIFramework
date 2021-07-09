#pragma once

#include "BaseListView.h"

namespace gui_framework
{
	/// @brief Base class for all list views in list mode
	class GUI_FRAMEWORK_API BaseListListView : public BaseListView
	{
	public:
		BaseListListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent);

		virtual ~BaseListListView() = default;
	};
}
