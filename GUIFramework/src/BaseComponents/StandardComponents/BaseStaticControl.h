#pragma once

#include "headers.h"
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
		inline static constexpr uint16_t staticControlWidth = 200;
		inline static constexpr uint16_t staticControlHeight = 40;

	public:
		BaseStaticControl(const std::wstring& staticControlName, const std::wstring& staticControlText, const utility::ComponentSettings& settings, BaseComponent* parent);

		/// @brief Used as key in creators
		/// @return typeid().hash_code()
		virtual size_t getHash() const override = 0;

		virtual ~BaseStaticControl() = default;
	};
}
