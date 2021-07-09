#pragma once

#include "BaseComponents/BaseComponent.h"

namespace gui_framework
{
	/// @brief Base class for all list views
	class GUI_FRAMEWORK_API BaseListView : virtual public BaseComponent
	{
	public:
		BaseListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent);

		virtual void setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue) final override;

		virtual void setTextColor(uint8_t red, uint8_t green, uint8_t blue) final override;

		virtual ~BaseListView() = default;
	};
}
