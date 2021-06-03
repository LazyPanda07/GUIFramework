#pragma once

#include "BaseComponent.h"
#include "Interfaces/Components/ITextOperations.h"

namespace gui_framework
{
	/// @brief Base class for all buttons
	class BaseButton :
		public BaseComponent,
		public interfaces::ITextOperations
	{
	protected:
		uint32_t buttonId;
		std::function<LRESULT(WPARAM, LPARAM)> onClick;

	public:
		BaseButton(const std::wstring& buttonName, const std::wstring& buttonText, const utility::ComponentSettings& settings, BaseComponent* parent, uint32_t buttonId, const std::function<LRESULT(WPARAM, LPARAM)>& onClick = nullptr);

		virtual LRESULT windowMessagesHandle(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam, bool& isUsed) = 0;

		virtual void setOnClick(const std::function<LRESULT(WPARAM, LPARAM)>& onClick) final;

		virtual const std::function<LRESULT(WPARAM, LPARAM)>& getOnClick() const final;

		virtual uint32_t getButtonId() const;

		~BaseButton() = default;
	};
}
