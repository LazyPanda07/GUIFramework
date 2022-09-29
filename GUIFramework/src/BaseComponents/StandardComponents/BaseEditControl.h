#pragma once

#include "core.h"
#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Components/ITextOperations.h"
#include "Interfaces/Localization/ISingleTextLocalized.h"

namespace gui_framework
{
	/// @brief Base class for all edit controls
	class GUI_FRAMEWORK_API BaseEditControl :
		public interfaces::ISingleTextLocalized,
		public BaseComponent,
		public interfaces::ITextOperations
	{
	public:
		inline static constexpr uint16_t editControlWidth = 200;
		inline static constexpr uint16_t editControlHeight = 20;

	protected:
		std::wstring placeholder;

	protected:
		virtual void updateLocalization(const std::wstring& localizedText) override;

	public:
		BaseEditControl(const std::wstring& editControlName, const utility::ComponentSettings& settings, BaseComposite* parent, bool isMultiLine = false);

		/// @brief Set placeholder to single line edit control
		/// @param placeholder 
		virtual bool setPlaceholder(const std::wstring& placeholder) final;

		virtual const std::wstring& getPlaceholder() const final;

		/// @brief Used as key in creators
		/// @return typeid().hash_code()
		virtual size_t getHash() const override = 0;

		virtual json::JSONBuilder getStructure() const override;

		virtual void setText(const std::string& localizationKey) final override;

		virtual ~BaseEditControl() = default;

		using interfaces::ITextOperations::setText;
	};
}
