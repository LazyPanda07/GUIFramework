#pragma once

#include "Core.h"
#include "Interfaces/Utility/IDeserializer.h"

namespace gui_framework
{
	namespace deserializers
	{
		/// @brief Deserialize ImageButton from JSON
		class GUI_FRAMEWORK_API ImageButtonDeserializer : public interfaces::IDeserializer
		{
		public:
			ImageButtonDeserializer() = default;

			BaseComponent* deserialize(const std::string& componentName, const json::utility::jsonObject& description, BaseComposite* parent) const override;

			~ImageButtonDeserializer() = default;
		};
	}
}
