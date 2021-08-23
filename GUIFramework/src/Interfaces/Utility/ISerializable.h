#pragma once

#include "headers.h"

namespace gui_framework
{
	namespace interfaces
	{
		/// @brief Provides interface for serializable to JSON format
		class GUI_FRAMEWORK_API ISerializable
		{
		private:
			uint32_t codepage;

		public:
			ISerializable();

			virtual void setCodepage(uint32_t codepage) final;

			virtual json::JSONBuilder getStructure() const = 0;

			virtual uint32_t getCodepage() const final;

			friend std::ostream& operator << (std::ostream& outputStream, const ISerializable& serializable);

			virtual ~ISerializable() = default;
		};
	}
}
