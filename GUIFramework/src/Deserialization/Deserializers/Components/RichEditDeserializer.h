#pragma once

#include "headers.h"
#include "Interfaces/Utility/IDeserializer.h"

namespace gui_framework
{
	namespace deserializers
	{
		/// @brief Deserialize RichEdit from JSON
		class GUI_FRAMEWORK_API RichEditDeserializer : public interfaces::IDeserializer
		{
		public:
			RichEditDeserializer() = default;

			BaseComponent* deserialize(const std::string& componentName, const json::utility::objectSmartPointer<json::utility::jsonObject>& description, BaseComposite* parent) const override;

			~RichEditDeserializer() = default;
		};
	}
}
