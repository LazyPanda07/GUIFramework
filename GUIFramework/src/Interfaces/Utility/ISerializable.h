#pragma once

#include "pch.h"

namespace gui_framework
{
	namespace interfaces
	{
		class GUI_FRAMEWORK_API ISerializable
		{
		private:
			uint32_t codepage;

		public:
			ISerializable();

			virtual void setCodepage(uint32_t codepage) final;

			virtual json::JSONBuilder getStructure(json::JSONBuilder* parentStructure = nullptr) const = 0;

			virtual uint32_t getCodepage() const final;

			friend std::ostream& operator << (std::ostream& outputStream, const ISerializable& serializable);

			virtual ~ISerializable() = default;
		};
	}
}
