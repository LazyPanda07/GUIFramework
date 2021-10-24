#pragma once

#include "headers.h"
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
		EditControl(const std::wstring& editControlName, const utility::ComponentSettings& settings, BaseComponent* parent, bool isMultiLine = false);

		size_t getHash() const override;

		~EditControl() = default;
	};
}
