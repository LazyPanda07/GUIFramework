#pragma once

#include "Interfaces/Menu/IMenuItem.h"

namespace gui_framework
{
	class BaseMenuItem : public interfaces::IMenuItem
	{
	public:
		BaseMenuItem(const std::wstring& text);

		virtual void processMessage() = 0;

		virtual std::tuple<uint32_t, uint64_t> getCreationData() const final override;

		virtual ~BaseMenuItem() = default;
	};
}
