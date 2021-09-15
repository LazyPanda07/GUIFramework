#pragma once

#include "Interfaces/Utility/IDeserializer.h"

namespace gui_framework
{
	namespace deserializers
	{
		class SeparateWindowDeserializer : public interfaces::IDeserializer
		{
		public:
			SeparateWindowDeserializer() = default;

			/// @brief SeparateWindow has no parent, you must manage the pointer
			/// @param className 
			/// @param description 
			/// @param parent Not used
			/// @return Not handled by parent
			virtual BaseComponent* deserialize(const std::string& className, const json::utility::objectSmartPointer<json::utility::jsonObject>& description, BaseComposite* parent = nullptr) const final override;

			~SeparateWindowDeserializer() = default;
		};
	}
}
