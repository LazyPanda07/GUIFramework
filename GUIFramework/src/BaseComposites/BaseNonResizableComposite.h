#pragma once

#include "BaseComposite.h"

namespace gui_framework
{
	class BaseNonResizableComposite : virtual public BaseComposite
	{
	public:
		BaseNonResizableComposite(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent = nullptr, const std::string& windowFunctionName = "");

		virtual ~BaseNonResizableComposite() = default;
	};
}
