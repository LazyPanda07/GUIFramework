#pragma once

#include "pch.h"

namespace gui_framework
{
	namespace interfaces
	{
		template<typename T, typename IBaseConstIteratorSubclass>
		class IBaseConstForwardIterator
		{
		public:
			IBaseConstForwardIterator() = default;

			virtual const T* operator * () const noexcept = 0;

			virtual const T* operator -> () const noexcept = 0;

			virtual IBaseConstForwardIterator<T, IBaseConstIteratorSubclass>& operator ++ () noexcept = 0;

			virtual IBaseConstIteratorSubclass operator ++ (int) noexcept = 0;

			virtual bool operator == (const IBaseConstForwardIterator<T, IBaseConstIteratorSubclass>& forward_iterator) const noexcept = 0;

			virtual bool operator != (const IBaseConstForwardIterator<T, IBaseConstIteratorSubclass>& forward_iterator) const noexcept = 0;

			virtual ~IBaseConstForwardIterator() = default;
		};
	}
}
