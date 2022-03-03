#pragma once

#include "headers.h"
#include "Interfaces/Utility/IDeserializer.h"

namespace gui_framework
{
	namespace deserializers
	{
		/// @brief Deserialize TextIconListView from JSON
		class GUI_FRAMEWORK_API TextIconListViewDeserializer : public interfaces::IDeserializer
		{
		public:
			TextIconListViewDeserializer() = default;

			BaseComponent* deserialize(const std::string& componentName, const json::utility::jsonObject& description, BaseComposite* parent) const override;

			~TextIconListViewDeserializer() = default;
		};
	}
}
