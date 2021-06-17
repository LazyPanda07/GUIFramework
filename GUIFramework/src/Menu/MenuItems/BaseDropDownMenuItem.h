#pragma once

#include "Interfaces/Menu/IMenuItem.h"

namespace gui_framework
{
	class BaseDropDownMenuItem : public interfaces::IMenuItem
	{
	protected:
		HMENU popupMenuHandle;

	public:
		BaseDropDownMenuItem(const std::wstring& text, HMENU popupMenuHandle);

		virtual void processMessage() = 0;

		virtual std::tuple<uint32_t, uint64_t> getCreationData() const final override;

		virtual ~BaseDropDownMenuItem() = default;
	};
}
