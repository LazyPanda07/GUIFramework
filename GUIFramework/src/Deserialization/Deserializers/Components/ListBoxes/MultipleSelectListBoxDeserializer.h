#pragma once

#include "Interfaces/Utility/IDeserializer.h"

namespace gui_framework
{
	namespace deserializers
	{
		/// @brief Deserialize MultipleSelectListBox from JSON
		class GUI_FRAMEWORK_API MultipleSelectListBoxDeserializer : public interfaces::IDeserializer
		{
		public:
			MultipleSelectListBoxDeserializer() = default;

			BaseComponent* deserialize(const std::string& componentName, const json::utility::jsonObject& description, BaseComposite* parent) const override;

			~MultipleSelectListBoxDeserializer() = default;
		};
	}
}
