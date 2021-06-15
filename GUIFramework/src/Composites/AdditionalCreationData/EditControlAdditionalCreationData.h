#pragma once

#include "AdditionalCreationData.h"
#include "Components/EditControl.h"

namespace gui_framework
{
	namespace utility
	{
		template<>
		class AdditionalCreationData<EditControl>
		{
		protected:
			std::wstring placeholder;

		public:
			AdditionalCreationData() = default;

			AdditionalCreationData(const std::wstring& placeholder);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};
	}
}
