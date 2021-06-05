#pragma once

#include "BaseComposite.h"
#include "Interfaces/Components/IResizableComponent.h"

namespace gui_framework
{
	class BaseResizableComposite :
		virtual public BaseComposite,
		public interfaces::IResizableComponent
	{
	protected:
		virtual LRESULT preWindowMessagesHandle(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam, bool& isUsed) override;

	public:
		BaseResizableComposite(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent = nullptr, const std::string& windowFunctionName = "");

		virtual void resize(uint16_t width, uint16_t height) override;

		virtual ~BaseResizableComposite() = default;
	};
}
