#pragma once

#include "pch.h"

namespace gui_framework
{
	namespace interfaces
	{
		class IMenuItem
		{
		protected:
			HMENU parent;
			uint32_t index;
			std::string type;

		public:
			IMenuItem(const std::string& type);

			virtual void setParent(HMENU parent) final;

			virtual void setIndex(uint32_t index) final;

			virtual const std::string& getMenuType() const final;

			virtual ~IMenuItem();
		};
	}
}
