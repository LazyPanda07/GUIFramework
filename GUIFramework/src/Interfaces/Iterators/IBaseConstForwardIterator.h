#pragma once

#include "Core.h"

namespace gui_framework
{
	namespace interfaces
	{
		/// @brief Base interface for const forward iterators
		/// @tparam T Type
		/// @tparam IBaseConstIteratorSubclass Class that implements IBaseConstForwardIterator
		template<typename T, typename IBaseConstIteratorSubclass>
		class GUI_FRAMEWORK_API IBaseConstForwardIterator
		{
		public:
			IBaseConstForwardIterator() = default;

			virtual const T* operator * () const noexcept = 0;

			virtual const T* operator -> () const noexcept = 0;

			virtual IBaseConstForwardIterator<T, IBaseConstIteratorSubclass>& operator ++ () noexcept = 0;

			virtual IBaseConstIteratorSubclass operator ++ (int) noexcept = 0;

			virtual bool operator == (const IBaseConstForwardIterator<T, IBaseConstIteratorSubclass>& const_forward_iterator) const noexcept = 0;

			virtual bool operator != (const IBaseConstForwardIterator<T, IBaseConstIteratorSubclass>& const_forward_iterator) const noexcept = 0;

			virtual ~IBaseConstForwardIterator() = default;
		};
	}
}
