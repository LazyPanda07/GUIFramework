#pragma once

#include "headers.h"
#include "Interfaces/Utility/IDeserializer.h"

namespace gui_framework
{
	namespace deserializers
	{
		/// @brief Deserialize DropDownListComboBox from JSON
		class GUI_FRAMEWORK_API DropDownListComboBoxDeserializer : public interfaces::IDeserializer
		{
		public:
			DropDownListComboBoxDeserializer() = default;

			BaseComponent* deserialize(const std::string& componentName, const json::utility::jsonObject& description, BaseComposite* parent) const override;

			~DropDownListComboBoxDeserializer() = default;
		};
	}
}
