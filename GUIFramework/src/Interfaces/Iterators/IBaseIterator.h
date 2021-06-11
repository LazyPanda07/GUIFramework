#pragma once

#include "IBaseConstIterator.h"

namespace gui_framework
{
	namespace interfaces
	{
		template<typename T, typename IBaseConstIteratorSubclass>
		class IBaseIterator : public IBaseConstIterator<T, IBaseConstIteratorSubclass>
		{
		public:
			IBaseIterator() = default;

			virtual T* operator * () noexcept = 0;

			virtual T* operator -> () noexcept = 0;

			virtual ~IBaseIterator() = default;
		};
	}
}
