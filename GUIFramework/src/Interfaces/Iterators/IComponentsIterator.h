#pragma once

#include "BaseComponents/BaseComponent.h"
#include "IBaseIterator.h"

namespace gui_framework
{
	namespace interfaces
	{
		class IComponentsIterator : public IBaseIterator<BaseComponent>
		{
		public:
			IComponentsIterator() = default;

			virtual ~IComponentsIterator() = default;
		};
	}
}
