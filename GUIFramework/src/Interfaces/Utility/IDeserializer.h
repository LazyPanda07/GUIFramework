#pragma once

#include "headers.h"
#include "BaseComposites/BaseComposite.h"

namespace gui_framework
{
	namespace interfaces
	{
		/// @brief Interface for all deserializers
		class GUI_FRAMEWORK_API IDeserializer
		{
		public:
			IDeserializer() = default;

			/// @brief Created component pointer already handled by its parent
			/// @param componentName Field name from JSON
			/// @param description Field data from JSON
			/// @param parent Parent composite or nullptr if has no parent
			/// @return 
			virtual BaseComponent* deserialize(const std::string& componentName, const json::utility::objectSmartPointer<json::utility::jsonObject>& description, BaseComposite* parent) const = 0;

			virtual ~IDeserializer() = default;
		};
	}
}
