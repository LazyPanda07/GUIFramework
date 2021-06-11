#pragma once

#include "IBaseIterator.h"

namespace gui_framework
{
	namespace interfaces
	{
		template<typename T, std::derived_from<IBaseIterator<T>> TIterator, std::derived_from<IBaseConstIterator<T>> TConstIterator>
		class IIterable
		{
		public:
			IIterable() = default;

			virtual TIterator begin() noexcept = 0;

			virtual TConstIterator cbegin() const noexcept = 0;

			virtual TIterator end() noexcept = 0;

			virtual TConstIterator cend() const noexcept = 0;

			virtual ~IIterable() = default;
		};
	}
}
