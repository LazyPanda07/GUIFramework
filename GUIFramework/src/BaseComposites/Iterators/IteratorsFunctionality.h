#pragma once

#include "pch.h"
#include "BaseComponents/BaseComponent.h"

namespace gui_framework
{
	namespace iterators
	{
		namespace utility
		{
			void getNextComponent(BaseComponent*& currentComponent, std::stack<BaseComponent*>& parents, std::stack<size_t>& indices);
		}
	}
}
