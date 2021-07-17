#pragma once

#include "pch.h"
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
		SeparateWindow(const std::wstring& className, const std::wstring& titleName, const utility::ComponentSettings& settings, const std::string& windowFunctionName, bool maximize = false, bool minimize = false);

		~SeparateWindow() = default;
	};
}
