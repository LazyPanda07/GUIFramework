#pragma once

#include "headers.h"
#include "Interfaces/Utility/IDeserializer.h"

namespace gui_framework
{
	namespace deserializers
	{
		/// @brief Deserialize TextListView from JSON
		class GUI_FRAMEWORK_API TextListViewDeserializer : public interfaces::IDeserializer
		{
		public:
			TextListViewDeserializer() = default;

			BaseComponent* deserialize(const std::string& componentName, const json::utility::jsonObject& description, BaseComposite* parent) const override;

			~TextListViewDeserializer() = default;
		};
	}
}
