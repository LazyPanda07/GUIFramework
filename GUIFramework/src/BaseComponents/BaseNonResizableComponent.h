#pragma once

#include "BaseComponent.h"
#include "Interfaces/Components/IResizableComponent.h"

namespace gui_framework
{
	class BaseNonResizableComponent : 
		virtual public BaseComponent,
		public interfaces::IResizableComponent
	{
	public:
		BaseNonResizableComponent(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent = nullptr, const std::string& windowFunctionName = "", const std::wstring& moduleName = L"");

		virtual void resize(uint16_t width, uint16_t height) final override;

		virtual ~BaseNonResizableComponent() = default;
	};
}
