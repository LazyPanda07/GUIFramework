#pragma once

#include "IBaseIterator.h"

namespace gui_framework
{
	namespace interfaces
	{
		template<typename T, typename TIterator, typename TConstIterator> requires (std::is_base_of_v<IBaseIterator<T, TIterator>, TIterator> && std::is_base_of_v<IBaseConstIterator<T, TConstIterator>, TConstIterator>)
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
