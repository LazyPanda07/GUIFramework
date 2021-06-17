#pragma once

#include "Interfaces/Menu/IMenuItem.h"

namespace gui_framework
{
	/// @brief Standard drop-down menu item
	class GUI_FRAMEWORK_API DropDownMenuItem : public interfaces::IMenuItem
	{
	protected:
		HMENU popupMenuHandle;

	public:
		DropDownMenuItem(const std::wstring& text, HMENU popupMenuHandle);

		virtual void processMessage() final;

		virtual std::tuple<uint32_t, uint64_t> getCreationData() const final override;

		virtual ~DropDownMenuItem() = default;
	};
}
