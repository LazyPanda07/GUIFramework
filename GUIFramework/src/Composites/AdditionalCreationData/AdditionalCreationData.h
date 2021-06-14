#pragma once

#include "pch.h"

namespace gui_framework
{
	namespace utility
	{
		template<typename T>
		class AdditionalCreationData
		{
		public:
			AdditionalCreationData() = default;

			virtual std::any getData() const = 0;

			virtual ~AdditionalCreationData() = default;
		};
	}
}
