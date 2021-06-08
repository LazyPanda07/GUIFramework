#pragma once

#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Components/ITextOperations.h"
#include "Interfaces/Components/IPlaceholder.h"

namespace gui_framework
{
	/// @brief Base class for all edit controls
	class BaseEditControl :
		virtual public BaseComponent,
		public interfaces::ITextOperations,
		public interfaces::IPlaceholder
	{
	public:
		BaseEditControl(const std::wstring& editControlName, const utility::ComponentSettings& settings, BaseComponent* parent);

		virtual ~BaseEditControl() = default;
	};
}
