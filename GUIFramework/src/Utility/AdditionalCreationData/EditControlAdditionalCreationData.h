#pragma once

#include "AdditionalCreationData.h"
#include "Components/EditControl.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Specialization for EditControl
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<EditControl>
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
