#pragma once

#include "headers.h"
#include "Interfaces/Utility/IDeserializer.h"

namespace gui_framework
{
	namespace deserializers
	{
		/// @brief Deserialize ListTextIconListView from JSON
		class GUI_FRAMEWORK_API ListTextIconListViewDeserializer : public interfaces::IDeserializer
		{
		public:
			ListTextIconListViewDeserializer() = default;

			BaseComponent* deserialize(const std::string& componentName, const json::utility::objectSmartPointer<json::utility::jsonObject>& description, BaseComposite* parent) const override;

			~ListTextIconListViewDeserializer() = default;
		};
	}
}
