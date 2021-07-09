#pragma once

#include "BaseButton.h"

namespace gui_framework
{
	/// @brief Base class for all check boxes
	class GUI_FRAMEWORK_API BaseCheckBox : public BaseButton
	{
	protected:
		std::function<LRESULT(WPARAM, LPARAM)> onCheck;
		std::function<LRESULT(WPARAM, LPARAM)> onClear;

	public:
		BaseCheckBox(const std::wstring& checkBoxName, const std::wstring& checkBoxText, const utility::ComponentSettings& settings, BaseComponent* parent, const std::function<LRESULT(WPARAM, LPARAM)>& onCheck, const std::function<LRESULT(WPARAM, LPARAM)>& onClear, const std::function<LRESULT(WPARAM, LPARAM)>& onClick = nullptr);

		virtual void setOnCheck(const std::function<LRESULT(WPARAM, LPARAM)>& onCheck) final;

		virtual void setOnClear(const std::function<LRESULT(WPARAM, LPARAM)>& onClear) final;

		virtual const std::function<LRESULT(WPARAM, LPARAM)>& getOnCheck() const final;

		virtual const std::function<LRESULT(WPARAM, LPARAM)>& getOnClear() const final;

		virtual LRESULT windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) final override;

		virtual ~BaseCheckBox() = default;
	};
}
