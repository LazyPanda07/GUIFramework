#pragma once

#include "pch.h"

namespace gui_framework
{
	namespace interfaces
	{
		template<typename T, typename IBaseConstIteratorSubclass>
		class IBaseConstIterator
		{
		public:
			IBaseConstIterator() = default;

			virtual const T* operator * () const noexcept = 0;

			virtual const T* operator -> () const noexcept = 0;

			virtual IBaseConstIterator<T, IBaseConstIteratorSubclass>& operator ++ () noexcept = 0;

			virtual IBaseConstIteratorSubclass operator ++ (int) noexcept = 0;

			virtual IBaseConstIterator<T, IBaseConstIteratorSubclass>& operator -- () noexcept = 0;

			virtual IBaseConstIteratorSubclass operator -- (int) noexcept = 0;

			virtual bool operator == (const IBaseConstIterator<T, IBaseConstIteratorSubclass>& iterator) const noexcept = 0;

			virtual bool operator != (const IBaseConstIterator<T, IBaseConstIteratorSubclass>& iterator) const noexcept = 0;

			virtual ~IBaseConstIterator() = default;
		};
	}
}
