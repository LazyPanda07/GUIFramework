#pragma once

#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Components/ITextOperations.h"
#include "Interfaces/Localization/ISingleTextLocalized.h"

namespace gui_framework
{
	/// @brief Base class for all static controls
	class GUI_FRAMEWORK_API BaseStaticControl :
		public interfaces::ISingleTextLocalized,
		public BaseComponent,
		public interfaces::ITextOperations
	{
	public:
		inline static constexpr uint16_t staticControlWidth = 200;
		inline static constexpr uint16_t staticControlHeight = 40;

	protected:
		virtual void updateLocalization(std::wstring_view localizedText) override;

	public:
		BaseStaticControl(const std::wstring& staticControlName, const std::wstring& staticControlText, const utility::ComponentSettings& settings, BaseComposite* parent);

		/// @brief Add border
		void addBorder();

		/// @brief Remove border
		void removeBorder();

		virtual void setText(std::string_view localizationKey) final override;

		/// @brief Used as key in creators
		/// @return typeid().hash_code()
		virtual size_t getHash() const override = 0;

		virtual ~BaseStaticControl() = default;

		using interfaces::ITextOperations::setText;
	};
}
