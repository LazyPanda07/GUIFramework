#pragma once

#include "Interfaces/Utility/IDeserializer.h"

namespace gui_framework
{
	namespace deserializers
	{
		/// @brief Deserialize Button from JSON
		class GUI_FRAMEWORK_API ButtonDeserializer : public interfaces::IDeserializer
		{
		public:
			ButtonDeserializer() = default;

			BaseComponent* deserialize(const std::string& componentName, const json::utility::jsonObject& description, BaseComposite* parent) const override;

			~ButtonDeserializer() = default;
		};
	}
}
