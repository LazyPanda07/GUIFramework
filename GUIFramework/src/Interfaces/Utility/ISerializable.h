#pragma once

#include "core.h"

namespace gui_framework
{
	namespace interfaces
	{
		/// @brief Provides interface for serializable to JSON format
		class GUI_FRAMEWORK_API ISerializable
		{
		public:
			static uint32_t getCodepage();

		public:
			ISerializable() = default;

			virtual json::JSONBuilder getStructure() const = 0;

			friend std::ostream& operator << (std::ostream& outputStream, const ISerializable& serializable);

			virtual ~ISerializable() = default;
		};

		inline uint32_t ISerializable::getCodepage()
		{
			return static_cast<uint32_t>(CP_UTF8);
		}
	}
}
