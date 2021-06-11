#pragma once

#include "IBaseIterator.h"

namespace gui_framework
{
	namespace interfaces
	{
		template<typename T>
		class IIterable
		{
		public:
			IIterable() = default;

			virtual std::unique_ptr<IBaseIterator<T>> begin() noexcept = 0;

			virtual std::unique_ptr<IBaseConstIterator<T>> cbegin() const noexcept = 0;

			virtual std::unique_ptr<IBaseIterator<T>> end() noexcept = 0;

			virtual std::unique_ptr<IBaseConstIterator<T>> cend() const noexcept = 0;

			virtual ~IIterable() = default;
		};
	}
}
