#pragma once

#include "headers.h"
#include "Interfaces/Utility/IDeserializer.h"

namespace gui_framework
{
	namespace deserializers
	{
		/// @brief Deserialize TabControl from JSON
		class GUI_FRAMEWORK_API TabControlDeserializer : public interfaces::IDeserializer
		{
		public:
			TabControlDeserializer() = default;

			BaseComponent* deserialize(const std::string& componentName, const json::utility::jsonObject& description, BaseComposite* parent) const override;

			~TabControlDeserializer() = default;
		};
	}
}
