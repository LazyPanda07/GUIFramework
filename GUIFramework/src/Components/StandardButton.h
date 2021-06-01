#pragma once

#include "BaseComponents/BaseButton.h"

namespace gui_framework
{
	class StandardButton : public BaseButton
	{
	public:
		StandardButton(const std::wstring& buttonName, const utility::ComponentSettings& settings, BaseComponent* parent, uint32_t buttonId, const std::function<LRESULT(WPARAM, LPARAM)>& onClick = nullptr);

		LRESULT windowMessagesHandle(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam, bool& isUsed) override;

		~StandardButton() = default;
	};
}
