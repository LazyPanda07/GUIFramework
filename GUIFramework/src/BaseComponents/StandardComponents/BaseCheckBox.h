#pragma once

#include "pch.h"
#include "BaseButton.h"

namespace gui_framework
{
	/// @brief Base class for all check boxes
	class GUI_FRAMEWORK_API BaseCheckBox : public BaseButton
	{
	protected:
		std::function<void()> onCheck;
		std::function<void()> onClear;
		std::string onCheckFunctionName;
		std::string onCheckModuleName;
		std::string onClearFunctionName;
		std::string onClearModuleName;

	private:
		virtual LRESULT windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) final override;

	public:
		BaseCheckBox(const std::wstring& checkBoxName, const std::wstring& checkBoxText, const utility::ComponentSettings& settings, BaseComponent* parent, const std::function<void()>& onCheck, const std::function<void()>& onClear, const std::function<void()>& onClick = nullptr);

		virtual void setOnCheck(const std::function<void()>& onCheck) final;

		virtual void setOnCheck(const std::string& functionName, const std::string& moduleName) final;

		virtual void setOnClear(const std::function<void()>& onClear) final;

		virtual void setOnClear(const std::string& functionName, const std::string& moduleName) final;

		virtual const std::function<void()>& getOnCheck() const final;

		virtual const std::function<void()>& getOnClear() const final;

		virtual json::JSONBuilder getStructure() const override;

		virtual ~BaseCheckBox() = default;
	};
}
