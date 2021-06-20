#pragma once

#include "BaseComponents/BaseResizableComponent.h"
#include "BaseComponents/StandardComponents/BaseTabControl.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API TabControl : 
		public BaseResizableComponent,
		public BaseTabControl
	{
	public:
		TabControl(const std::wstring& tabControlName, const utility::ComponentSettings& settings, BaseComponent* parent, uint16_t imagesWidth = NULL, uint16_t imagesHeight = NULL);

		~TabControl() = default;
	};
}
