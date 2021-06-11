#pragma once

#include "IBaseForwardIterator.h"

namespace gui_framework
{
	namespace interfaces
	{
		template<typename T, typename TForwardIterator, typename TConstForwardIterator> requires (std::is_base_of_v<IBaseForwardIterator<T, TForwardIterator>, TForwardIterator> && std::is_base_of_v<IBaseConstForwardIterator<T, TConstForwardIterator>, TConstForwardIterator>)
		class IIterable
		{
		public:
			IIterable() = default;

			virtual TForwardIterator begin() noexcept = 0;

			virtual TConstForwardIterator cbegin() const noexcept = 0;

			virtual TForwardIterator end() noexcept = 0;

			virtual TConstForwardIterator cend() const noexcept = 0;

			virtual ~IIterable() = default;
		};
	}
}
