#pragma once

#include "headers.h"
#include "Interfaces/Utility/IDeserializer.h"

namespace gui_framework
{
	namespace deserializers
	{
		class GUI_FRAMEWORK_API VerticalTrackbarControlDeserializer : public interfaces::IDeserializer
		{
		public:
			VerticalTrackbarControlDeserializer() = default;

			BaseComponent* deserialize(const std::string& componentName, const json::utility::objectSmartPointer<json::utility::jsonObject>& description, BaseComposite* parent) const override;

			~VerticalTrackbarControlDeserializer() = default;
		};
	}
}
