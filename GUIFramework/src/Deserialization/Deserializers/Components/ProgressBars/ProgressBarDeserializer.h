#pragma once

#include "headers.h"
#include "Interfaces/Utility/IDeserializer.h"

namespace gui_framework
{
	namespace deserializers
	{
		/// @brief Deserialize ProgressBar from JSON
		class GUI_FRAMEWORK_API ProgressBarDeserializer : public interfaces::IDeserializer
		{
		public:
			ProgressBarDeserializer() = default;

			BaseComponent* deserialize(const std::string& componentName, const json::utility::objectSmartPointer<json::utility::jsonObject>& description, BaseComposite* parent) const override;

			~ProgressBarDeserializer() = default;
		};
	}
}
