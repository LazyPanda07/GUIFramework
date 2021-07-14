#pragma once

#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Components/ITextOperations.h"

namespace gui_framework
{
	/// @brief Base class for all static controls
	class GUI_FRAMEWORK_API BaseStaticControl :
		public BaseComponent,
		public interfaces::ITextOperations
	{
	public:
		BaseStaticControl(const std::wstring& staticControlName, const std::wstring& staticControlText, const utility::ComponentSettings& settings, BaseComponent* parent);

		virtual ~BaseStaticControl() = default;
	};
}
