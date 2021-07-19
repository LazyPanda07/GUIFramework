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

			virtual json::JSONBuilder getStructure() const = 0;

			virtual uint32_t getCodepage() const final;

			virtual std::ostream& operator << (std::ostream& outputStream) const final;

			virtual ~ISerializable() = default;
		};
	}
}
