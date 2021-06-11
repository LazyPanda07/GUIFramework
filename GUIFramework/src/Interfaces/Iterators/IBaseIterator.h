#pragma once

#include "IBaseConstIterator.h"

namespace gui_framework
{
	namespace interfaces
	{
		template<typename T>
		class IBaseIterator : public IBaseConstIterator<T>
		{
		public:
			IBaseIterator() = default;

			virtual T* operator * () noexcept = 0;

			virtual T* operator -> () noexcept = 0;

			virtual ~IBaseIterator() = default;
		};
	}
}
