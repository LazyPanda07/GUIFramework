#pragma once

#include "Core.h"
#include "Interfaces/Utility/IDeserializer.h"

namespace gui_framework
{
	namespace deserializers
	{
		/// @brief Deserialize DropDownComboBox from JSON
		class GUI_FRAMEWORK_API DropDownComboBoxDeserializer : public interfaces::IDeserializer
		{
		public:
			DropDownComboBoxDeserializer() = default;

			BaseComponent* deserialize(const std::string& componentName, const json::utility::jsonObject& description, BaseComposite* parent) const override;

			~DropDownComboBoxDeserializer() = default;
		};
	}
}
