#pragma once

#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Components/ITextOperations.h"

namespace gui_framework
{
	/// @brief Base class for all buttons
	class BaseButton :
		virtual public BaseComponent,
		public interfaces::ITextOperations
	{
	protected:
		uint64_t buttonId;
		std::function<LRESULT(WPARAM, LPARAM)> onClick;

	private:
		HMENU initButtonId(uint64_t buttonId);

	public:
		BaseButton(const std::wstring& buttonName, const std::wstring& buttonText, const utility::ComponentSettings& settings, BaseComponent* parent, const std::function<LRESULT(WPARAM, LPARAM)>& onClick = nullptr);

		virtual LRESULT windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) = 0;

		virtual void setOnClick(const std::function<LRESULT(WPARAM, LPARAM)>& onClick) final;

		virtual const std::function<LRESULT(WPARAM, LPARAM)>& getOnClick() const final;

		virtual uint64_t getButtonId() const;

		~BaseButton() = default;
	};
}
