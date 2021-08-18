#pragma once

#include "pch.h"
#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Components/ITextOperations.h"

namespace gui_framework
{
	/// @brief Base class for all edit controls
	class GUI_FRAMEWORK_API BaseEditControl :
		public BaseComponent,
		public interfaces::ITextOperations
	{
	protected:
		std::wstring placeholder;

	public:
		BaseEditControl(const std::wstring& editControlName, const utility::ComponentSettings& settings, BaseComponent* parent, bool isMultiLine = false);

		/// @brief Set placeholder to single line edit control
		/// @param placeholder 
		virtual bool setPlaceholder(const std::wstring& placeholder) final;

		virtual const std::wstring& getPlaceholder() const final;

		virtual json::JSONBuilder getStructure() const override;

		virtual ~BaseEditControl() = default;
	};
}
