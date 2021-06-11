#pragma once

#include "IBaseConstForwardIterator.h"

namespace gui_framework
{
	namespace interfaces
	{
		template<typename T, typename IBaseConstIteratorSubclass>
		class IBaseForwardIterator : public IBaseConstForwardIterator<T, IBaseConstIteratorSubclass>
		{
		public:
			IBaseForwardIterator() = default;

			virtual T* operator * () noexcept = 0;

			virtual T* operator -> () noexcept = 0;

			virtual ~IBaseForwardIterator() = default;
		};
	}
}
