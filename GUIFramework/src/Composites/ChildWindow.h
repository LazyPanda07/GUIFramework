#pragma once

#include "headers.h"
#include "BaseComposites/StandardComposites/BaseChildWindow.h"
#include "Interfaces/Components/IResizableComponent.h"

namespace gui_framework
{
	/// @brief Standard child window
	class GUI_FRAMEWORK_API ChildWindow :
		public BaseChildWindow,
		public interfaces::IResizableComponent	
	{
	public:
		ChildWindow(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent, const std::string& windowFunctionName = "");

		size_t getHash() const override;

		~ChildWindow() = default;
	};
}
