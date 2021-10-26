#pragma once

#include "headers.h"
#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Components/ITextOperations.h"

namespace gui_framework
{
	/// @brief Base class for all edit controls
	class GUI_FRAMEWORK_API BaseEditControl :
		public BaseComponent,
		public interfaces::ITextOperations
	{
	public:
		inline static constexpr uint16_t editControlWidth = 200;
		inline static constexpr uint16_t editControlHeight = 20;

	protected:
		std::wstring placeholder;

	public:
		BaseEditControl(const std::wstring& editControlName, const utility::ComponentSettings& settings, BaseComponent* parent, bool isMultiLine = false);

		/// @brief Set placeholder to single line edit control
		/// @param placeholder 
		virtual bool setPlaceholder(const std::wstring& placeholder) final;

		virtual const std::wstring& getPlaceholder() const final;

		/// @brief Used as key in creators
		/// @return typeid().hash_code()
		virtual size_t getHash() const override = 0;

		virtual json::JSONBuilder getStructure() const override;

		virtual ~BaseEditControl() = default;
	};
}
