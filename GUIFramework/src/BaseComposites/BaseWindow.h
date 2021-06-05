#pragma once

#include "BaseComposite.h"

namespace gui_framework
{
	/// @brief Base class for composite windows
	class BaseWindow : virtual public BaseComposite
	{
	public:
		BaseWindow(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent = nullptr, const std::string& windowFunctionName = "");

		virtual ~BaseWindow() = default;
	};
}
