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

		protected:
			virtual json::JSONBuilder getStructure() const = 0;

		public:
			ISerializable();

			virtual void setCodepage(uint32_t codepage) final;

			virtual uint32_t getCodepage() const final;

			virtual std::ostream& operator << (std::ostream& outputStream) const final;

			virtual ~ISerializable() = default;
		};
	}
}
