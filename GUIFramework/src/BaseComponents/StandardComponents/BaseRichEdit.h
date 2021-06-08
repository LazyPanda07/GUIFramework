#pragma once

#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Components/IResizableComponent.h"
#include "Interfaces/Components/ITextOperations.h"

namespace gui_framework
{
	class BaseRichEdit :
		virtual public BaseComponent,
		public interfaces::IResizableComponent,
		public interfaces::ITextOperations
	{
	public:
		BaseRichEdit(const std::wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent);

		virtual ~BaseRichEdit() = default;
	};
}
