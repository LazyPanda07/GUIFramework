#pragma once

#include "BaseComponents/BaseComponent.h"

namespace gui_framework
{
	/// @brief Base class for all list views
	class GUI_FRAMEWORK_API BaseListView : virtual public BaseComponent
	{
	public:
		BaseListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent);

		virtual ~BaseListView() = default;
	};
}
