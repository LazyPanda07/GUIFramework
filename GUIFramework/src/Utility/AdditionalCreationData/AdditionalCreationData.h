#pragma once

#include "core.h"
#include "BaseComponents/BaseComponent.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Base templated class for component creators
		template<std::derived_from<BaseComponent> T>
		class GUI_FRAMEWORK_API AdditionalCreationData
		{
		public:
			AdditionalCreationData() = default;

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};

		template<std::derived_from<BaseComponent> T>
		std::any AdditionalCreationData<T>::getData() const
		{
			return std::any();
		}
	}
}
