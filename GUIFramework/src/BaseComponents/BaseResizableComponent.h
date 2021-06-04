#pragma once

#include "BaseComponent.h"
#include "Interfaces/Components/IResizableComponent.h"

namespace gui_framework
{
	class BaseResizableComponent :
		virtual public BaseComponent,
		public interfaces::IResizableComponent
	{
	protected:
		virtual LRESULT preWindowMessagesHandle(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam, bool& isUsed) override;

	public:
		BaseResizableComponent(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent = nullptr, const std::string& windowFunctionName = "", const std::wstring& moduleName = L"");

		virtual void resize(uint16_t width, uint16_t height) override;

		virtual ~BaseResizableComponent() = default;
	};
}
