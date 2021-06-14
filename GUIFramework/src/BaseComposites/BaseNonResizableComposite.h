#pragma once

#include "BaseComposite.h"
#include "Interfaces/Components/IResizableComponent.h"

namespace gui_framework
{
	class BaseNonResizableComposite : 
		virtual public BaseComposite,
		public interfaces::IResizableComponent
	{
	public:
		BaseNonResizableComposite(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent = nullptr, const std::string& windowFunctionName = "");

		virtual void resize(uint16_t width, uint16_t height) final override;

		virtual ~BaseNonResizableComposite() = default;
	};
}
