#pragma once

#include "BaseComponents/BaseButton.h"

namespace gui_framework
{
	/// @brief Standard button
	class StandardButton : public BaseButton
	{
	public:
		StandardButton(const std::wstring& buttonName, int x, int y, BaseComponent* parent, uint32_t buttonId, int width = standard_sizes::buttonWidth, int height = standard_sizes::buttonHeight, const std::function<LRESULT(WPARAM, LPARAM)>& onClick = nullptr);

		LRESULT windowMessagesHandle(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam, bool& isUsed) override;

		~StandardButton() = default;
	};
}
