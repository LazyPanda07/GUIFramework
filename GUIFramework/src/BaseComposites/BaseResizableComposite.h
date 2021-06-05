#pragma once

#include "BaseComposite.h"
#include "Interfaces/Components/IResizableComponent.h"

namespace gui_framework
{
	class BaseResizableComposite :
		virtual public BaseComposite,
		public interfaces::IResizableComponent
	{
	public:
		BaseResizableComposite(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent = nullptr, const std::string& windowFunctionName = "");

		virtual ~BaseResizableComposite() = default;
	};
}
