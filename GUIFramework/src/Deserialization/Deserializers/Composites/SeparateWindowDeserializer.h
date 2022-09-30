#pragma once

#include "Interfaces/Utility/IDeserializer.h"

namespace gui_framework
{
	namespace deserializers
	{
		/// @brief Deserialize SeparateWindow from JSON
		class GUI_FRAMEWORK_API SeparateWindowDeserializer : public interfaces::IDeserializer
		{
		public:
			SeparateWindowDeserializer() = default;

			/// @brief SeparateWindow has no parent, you must manage the pointer
			/// @param componentName 
			/// @param description 
			/// @param parent Not used
			/// @return Not handled by parent
			/// @exception WrongMenuTypeException
			BaseComponent* deserialize(const std::string& componentName, const json::utility::jsonObject& description, BaseComposite* parent = nullptr) const override;

			~SeparateWindowDeserializer() = default;
		};
	}
}
