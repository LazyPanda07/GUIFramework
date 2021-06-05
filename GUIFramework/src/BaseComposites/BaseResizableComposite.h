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
		virtual LRESULT preWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) override;

	public:
		BaseResizableComposite(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent = nullptr, const std::string& windowFunctionName = "");

		virtual ~BaseResizableComposite() = default;
	};
}
