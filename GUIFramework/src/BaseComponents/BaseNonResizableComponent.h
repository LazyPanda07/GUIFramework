#pragma once

#include "BaseComponent.h"

namespace gui_framework
{
	class BaseNonResizableComponent : public BaseComponent
	{
	public:
		BaseNonResizableComponent(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent = nullptr, const std::string& windowFunctionName = "", const std::wstring& moduleName = L"");

		virtual ~BaseNonResizableComponent() = default;
	};
}
