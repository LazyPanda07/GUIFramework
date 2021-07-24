#pragma once

#include "pch.h"
#include "BaseComposites/BaseComposite.h"

namespace gui_framework
{
	/// @brief Base class for composite windows
	class GUI_FRAMEWORK_API BaseWindow : public BaseComposite
	{
	public:
		BaseWindow(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, const interfaces::IStyles& styles, BaseComponent* parent = nullptr, const std::string& windowFunctionName = "");

		virtual ~BaseWindow() = default;
	};
}
