#pragma once

#include "core.h"
#include "BaseComponents/StandardComponents/BaseStaticControl.h"
#include "Interfaces/Components/IResizableComponent.h"

namespace gui_framework
{
	/// @brief Standard static control
	class GUI_FRAMEWORK_API StaticControl :
		public BaseStaticControl,
		public interfaces::IResizableComponent
	{
	public:
		StaticControl(const std::wstring& staticControlName, const std::wstring& editControlText, const utility::ComponentSettings& settings, BaseComponent* parent);

		size_t getHash() const override;

		~StaticControl() = default;
	};
}
