#pragma once

#include "Interfaces/Utility/IDeserializer.h"

namespace gui_framework
{
	namespace deserializers
	{
		/// @brief Deserialize IconListView from JSON
		class GUI_FRAMEWORK_API IconListViewDeserializer : public interfaces::IDeserializer
		{
		public:
			IconListViewDeserializer() = default;

			BaseComponent* deserialize(const std::string& componentName, const json::utility::jsonObject& description, BaseComposite* parent) const override;

			~IconListViewDeserializer() = default;
		};
	}
}
