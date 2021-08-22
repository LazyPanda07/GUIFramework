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
		/// @brief 
		/// @param moduleName Name of loaded resource module with icons
		/// @param smallIconResource Integer value from auto generated Visual Studio resources
		/// @param largeIconResource Integer value from auto generated Visual Studio resources
		BaseSeparateWindow(const std::wstring& className, const std::wstring& titleName, const utility::ComponentSettings& settings, const std::string& windowFunctionName, bool maximize = false, bool minimize = false, const std::string& moduleName = "", uint16_t smallIconResource = NULL, uint16_t largeIconResource = NULL);

		virtual ~BaseSeparateWindow() = default;
	};
}
