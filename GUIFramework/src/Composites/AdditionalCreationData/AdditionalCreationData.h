#pragma once

#include "pch.h"
#include "BaseComponents/BaseComponent.h"

namespace gui_framework
{
	namespace utility
	{
		template<std::derived_from<BaseComponent> T>
		class AdditionalCreationData
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
