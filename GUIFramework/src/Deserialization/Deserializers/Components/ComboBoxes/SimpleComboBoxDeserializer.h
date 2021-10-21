#pragma once

#include "headers.h"
#include "Interfaces/Utility/IDeserializer.h"

namespace gui_framework
{
	namespace deserializers
	{
		/// @brief Deserialize SimpleComboBox from JSON
		class GUI_FRAMEWORK_API SimpleComboBoxDeserializer : public interfaces::IDeserializer
		{
		public:
			SimpleComboBoxDeserializer() = default;

			BaseComponent* deserialize(const std::string& componentName, const json::utility::objectSmartPointer<json::utility::jsonObject>& description, BaseComposite* parent) const override;

			~SimpleComboBoxDeserializer() = default;
		};
	}
}
