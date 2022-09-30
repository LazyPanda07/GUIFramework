#pragma once

#include "Interfaces/Utility/IDeserializer.h"

namespace gui_framework
{
	namespace deserializers
	{
		/// @brief Deserialize InfiniteProgressBar from JSON
		class GUI_FRAMEWORK_API InfiniteProgressBarDeserializer : public interfaces::IDeserializer
		{
		public:
			InfiniteProgressBarDeserializer() = default;

			BaseComponent* deserialize(const std::string& componentName, const json::utility::jsonObject& description, BaseComposite* parent) const override;

			~InfiniteProgressBarDeserializer() = default;
		};
	}
}
