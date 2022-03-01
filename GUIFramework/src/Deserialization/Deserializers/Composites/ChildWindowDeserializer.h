#pragma once

#include "headers.h"
#include "Interfaces/Utility/IDeserializer.h"

namespace gui_framework
{
	namespace deserializers
	{
		/// @brief Deserialize ChildWindow from JSON
		class GUI_FRAMEWORK_API ChildWindowDeserializer : public interfaces::IDeserializer
		{
		public:
			ChildWindowDeserializer() = default;

			BaseComponent* deserialize(const std::string& componentName, const json::utility::jsonObject& description, BaseComposite* parent) const override;

			~ChildWindowDeserializer() = default;
		};
	}
}
