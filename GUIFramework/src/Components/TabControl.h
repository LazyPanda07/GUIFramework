#pragma once

#include "BaseComponents/StandardComponents/BaseTabControl.h"
#include "Interfaces/Components/IResizableComponent.h"

namespace gui_framework
{
	/// @brief Standard tab control
	class GUI_FRAMEWORK_API TabControl : 
		public BaseTabControl,
		public interfaces::IResizableComponent
	{
	public:
		TabControl(const std::wstring& tabControlName, const utility::ComponentSettings& settings, BaseComposite* parent, uint16_t imagesWidth = NULL, uint16_t imagesHeight = NULL);

		size_t getHash() const override;

		json::JSONBuilder getStructure() const override;

		~TabControl() = default;
	};
}
