#pragma once

#include "headers.h"
#include "BaseComposites/StandardComposites/BaseSeparateWindow.h"
#include "Interfaces/Components/IResizableComponent.h"

namespace gui_framework
{
	/// @brief Standard separate window
	class GUI_FRAMEWORK_API SeparateWindow :
		public BaseSeparateWindow,
		public interfaces::IResizableComponent
	{
	public:
		/// @brief 
		/// @param moduleName Name of loaded resource module with icons
		/// @param smallIconResource Integer value from auto generated Visual Studio resources
		/// @param largeIconResource Integer value from auto generated Visual Studio resources
		SeparateWindow(const std::wstring& className, const std::wstring& titleName, const utility::ComponentSettings& settings, const std::string& windowFunctionName, bool maximize = false, bool minimize = false, const std::string& moduleName = "", uint16_t smallIconResource = NULL, uint16_t largeIconResource = NULL);

		size_t getHash() const override;

		~SeparateWindow() = default;
	};
}
