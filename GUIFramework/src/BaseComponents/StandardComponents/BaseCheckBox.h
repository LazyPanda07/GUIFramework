#pragma once

#include "BaseButton.h"

namespace gui_framework
{
	/// @brief Base class for all check boxes
	class GUI_FRAMEWORK_API BaseCheckBox : public BaseButton
	{
	protected:
		std::function<void()> onCheck;
		std::function<void()> onClear;

	private:
		virtual LRESULT windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) final override;

	public:
		BaseCheckBox(const std::wstring& checkBoxName, const std::wstring& checkBoxText, const utility::ComponentSettings& settings, BaseComponent* parent, const std::function<void()>& onCheck, const std::function<void()>& onClear, const std::function<void()>& onClick = nullptr);

		virtual void setOnCheck(const std::function<void()>& onCheck) final;

		virtual void setOnClear(const std::function<void()>& onClear) final;

		virtual const std::function<void()>& getOnCheck() const final;

		virtual const std::function<void()>& getOnClear() const final;

		virtual ~BaseCheckBox() = default;
	};
}
