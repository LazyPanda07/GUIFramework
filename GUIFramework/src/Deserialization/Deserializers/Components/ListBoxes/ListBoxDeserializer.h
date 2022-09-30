#pragma once

#include "Core.h"
#include "Interfaces/Utility/IDeserializer.h"

namespace gui_framework
{
	namespace deserializers
	{
		/// @brief Deserialize ListBox from JSON
		class GUI_FRAMEWORK_API ListBoxDeserializer : public interfaces::IDeserializer
		{
		public:
			ListBoxDeserializer() = default;

			BaseComponent* deserialize(const std::string& componentName, const json::utility::jsonObject& description, BaseComposite* parent) const override;

			~ListBoxDeserializer() = default;
		};
	}
}
