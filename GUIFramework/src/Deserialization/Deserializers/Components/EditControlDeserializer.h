#pragma once

#include "headers.h"
#include "Interfaces/Utility/IDeserializer.h"

namespace gui_framework
{
	namespace deserializers
	{
		/// @brief Deserialize EditControl from JSON
		class GUI_FRAMEWORK_API EditControlDeserializer : public interfaces::IDeserializer
		{
		public:
			EditControlDeserializer() = default;

			BaseComponent* deserialize(const std::string& componentName, const json::utility::objectSmartPointer<json::utility::jsonObject>& description, BaseComposite* parent) const override;

			~EditControlDeserializer() = default;
		};
	}
}
