#pragma once

#include "core.h"
#include "Interfaces/Utility/IDeserializer.h"

namespace gui_framework
{
	namespace deserializers
	{
		/// @brief Deserialize HorizontalTrackbarControl from JSON
		class GUI_FRAMEWORK_API HorizontalTrackbarControlDeserializer : public interfaces::IDeserializer
		{
		public:
			HorizontalTrackbarControlDeserializer() = default;

			BaseComponent* deserialize(const std::string& componentName, const json::utility::jsonObject& description, BaseComposite* parent) const override;

			~HorizontalTrackbarControlDeserializer() = default;
		};
	}
}
