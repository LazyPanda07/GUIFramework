#pragma once

#include "BaseComponents/BaseComponent.h"

namespace gui_framework
{
	class BaseComposite : public BaseComponent
	{
	protected:
		std::vector<std::unique_ptr<BaseComponent>> children;

	public:
		BaseComposite(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent = nullptr, const std::string& windowFunctionName = "");

		/// @brief Add child window
		/// @param child BaseComposite takes control for all children
		virtual void addChild(BaseComponent* child) final;

		virtual void removeChild(BaseComponent* child) final;

		virtual bool isComposite() const final override;

		virtual LRESULT windowMessagesHandle(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam, bool& isUsed) override;

		virtual ~BaseComposite() = default;
	};
}
