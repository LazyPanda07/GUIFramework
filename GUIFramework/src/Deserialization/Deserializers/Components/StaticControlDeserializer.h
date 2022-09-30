#pragma once

#include "Core.h"
#include "Interfaces/Utility/IDeserializer.h"

namespace gui_framework
{
	namespace deserializers
	{
		/// @brief Deserialize StaticControl from JSON
		class GUI_FRAMEWORK_API StaticControlDeserializer : public interfaces::IDeserializer
		{
		public:
			StaticControlDeserializer() = default;

			BaseComponent* deserialize(const std::string& componentName, const json::utility::jsonObject& description, BaseComposite* parent) const override;

			~StaticControlDeserializer() = default;
		};
	}
}
