#pragma once

#include "BaseComponents/BaseComponent.h"
#include "Styles/Components/ListViews/ListViewStyles.h"

namespace gui_framework
{
	/// @brief Base class for all list views
	class GUI_FRAMEWORK_API BaseListView : public BaseComponent
	{
	public:
		BaseListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, const styles::ListViewStyles& styles, BaseComponent* parent);

		virtual void setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue) final override;

		virtual void setTextColor(uint8_t red, uint8_t green, uint8_t blue) override;

		virtual ~BaseListView() = default;
	};
}
