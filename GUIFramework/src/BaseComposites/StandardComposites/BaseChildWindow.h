#pragma once

#include "BaseWindow.h"

namespace gui_framework
{
	/// @brief Base class for all nested windows
	class GUI_FRAMEWORK_API BaseChildWindow : public BaseWindow
	{
	public:
		BaseChildWindow(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, BaseComposite* parent, const std::string& windowFunctionName = "");

		/// @brief Used as key in creators
		/// @return typeid().hash_code()
		virtual size_t getHash() const override = 0;

		virtual ~BaseChildWindow() = default;
	};
}
