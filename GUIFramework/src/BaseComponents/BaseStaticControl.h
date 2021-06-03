#pragma once

#include "BaseComponent.h"
#include "Interfaces/Components/ITextOperations.h"

namespace gui_framework
{
	class BaseStaticControl :
		public BaseComponent,
		public interfaces::ITextOperations
	{
	public:
		BaseStaticControl(const std::wstring& staticControlName, const std::wstring& staticControlText, const utility::ComponentSettings& settings, BaseComponent* parent);

		virtual ~BaseStaticControl() = default;
	};
}
