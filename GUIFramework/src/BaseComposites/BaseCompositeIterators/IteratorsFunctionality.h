#pragma once

#include "BaseComponents/BaseComponent.h"

namespace gui_framework
{
	namespace iterators
	{
		namespace utility
		{
			void getNextComponent(BaseComponent*& currentComponent, std::stack<BaseComponent*>& parents, std::stack<size_t>& indices);

			void getPreviousComponent(BaseComponent*& currentComponent, std::stack<BaseComponent*>& parents, std::stack<size_t>& indices);
		}
	}
}
