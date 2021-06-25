#pragma once

#include "BaseListView.h"

namespace gui_framework
{
	class BaseListListView : public BaseListView
	{
	public:
		BaseListListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent);

		virtual ~BaseListListView() = default;
	};
}
