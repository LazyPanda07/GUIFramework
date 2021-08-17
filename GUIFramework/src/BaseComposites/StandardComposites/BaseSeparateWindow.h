#pragma once

#include "pch.h"
#include "BaseWindow.h"

namespace gui_framework
{
	/// @brief Base class for separate windows
	class GUI_FRAMEWORK_API BaseSeparateWindow : public BaseWindow
	{
	protected:
		virtual const std::string& getCreationType() const override;

	public:
		/// @brief Create new separate window
		BaseSeparateWindow(const std::wstring& className, const std::wstring& titleName, const utility::ComponentSettings& settings, const std::string& windowFunctionName, bool maximize = false, bool minimize = false);

		virtual ~BaseSeparateWindow() = default;
	};
}
