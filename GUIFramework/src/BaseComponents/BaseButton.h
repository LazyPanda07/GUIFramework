#pragma once

#include "BaseComponent.h"

namespace gui_framework
{
	class BaseButton : public BaseComponent
	{
	protected:
		uint32_t buttonId;
		std::function<LRESULT(WPARAM, LPARAM)> onClick;

	public:
		BaseButton(const std::wstring& buttonName, const utility::ComponentSettings& settings, BaseComponent* parent, uint32_t buttonId, const std::function<LRESULT(WPARAM, LPARAM)>& onClick = nullptr);

		virtual LRESULT windowMessagesHandle(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam, bool& isUsed) = 0;

		virtual void setOnClick(const std::function<LRESULT(WPARAM, LPARAM)>& onClick) final;

		virtual const std::function<LRESULT(WPARAM, LPARAM)>& getOnClick() const final;

		~BaseButton() = default;
	};
}
