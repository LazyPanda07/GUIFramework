#pragma once

#include "BaseComponents/BaseComponent.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API BaseListView : virtual public BaseComponent
	{
	protected:
		virtual LRESULT addItem(const LVITEMW& item) final;

	public:
		BaseListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent);

		virtual ~BaseListView() = default;
	};
}
