#pragma once

#include "Interfaces/Utility/IDeserializer.h"

namespace gui_framework
{
	namespace deserializers
	{
		/// @brief Deserialize ListIconListView from JSON
		class GUI_FRAMEWORK_API ListIconListViewDeserializer : public interfaces::IDeserializer
		{
		public:
			ListIconListViewDeserializer() = default;

			BaseComponent* deserialize(const std::string& componentName, const json::utility::jsonObject& description, BaseComposite* parent) const override;

			~ListIconListViewDeserializer() = default;
		};
	}
}
