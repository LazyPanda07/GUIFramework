#pragma once

#include "Interfaces/Utility/IDeserializer.h"

namespace gui_framework
{
	namespace deserializers
	{
		/// @brief Deserialize CheckBox from JSON
		class GUI_FRAMEWORK_API CheckBoxDeserializer : public interfaces::IDeserializer
		{
		public:
			CheckBoxDeserializer() = default;

			BaseComponent* deserialize(const std::string& componentName, const json::utility::jsonObject& description, BaseComposite* parent) const override;

			~CheckBoxDeserializer() = default;
		};
	}
}
