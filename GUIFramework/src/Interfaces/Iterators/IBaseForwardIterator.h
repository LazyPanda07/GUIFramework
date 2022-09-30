#pragma once

#include "IBaseConstForwardIterator.h"

namespace gui_framework
{
	namespace interfaces
	{
		/// @brief Base interface for forward iterators
		/// @tparam T Type
		/// @tparam IBaseConstIteratorSubclass Class that implements IBaseConstForwardIterator
		template<typename T, typename IBaseConstIteratorSubclass>
		class GUI_FRAMEWORK_API IBaseForwardIterator : public IBaseConstForwardIterator<T, IBaseConstIteratorSubclass>
		{
		public:
			IBaseForwardIterator() = default;

			virtual T* operator * () noexcept = 0;

			virtual T* operator -> () noexcept = 0;

			virtual ~IBaseForwardIterator() = default;
		};
	}
}
