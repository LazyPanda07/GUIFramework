#pragma once

#include "pch.h"
#include "BaseComponents/StandardComponents/BaseEditControl.h"
#include "Interfaces/Components/IResizableComponent.h"

namespace gui_framework
{
	/// @brief Standard edit control
	class GUI_FRAMEWORK_API EditControl :
		public BaseEditControl,
		public interfaces::IResizableComponent
	{
	public:
		EditControl(const std::wstring& editControlName, int x, int y, BaseComponent* parent, uint16_t width = standard_sizes::editControlWidth, uint16_t height = standard_sizes::editControlHeight);

		~EditControl() = default;
	};
}
