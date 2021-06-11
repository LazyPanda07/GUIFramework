#pragma once

#include "pch.h"

namespace gui_framework
{
	namespace interfaces
	{
		template<typename T>
		class IBaseConstIterator
		{
		public:
			IBaseConstIterator() = default;

			virtual const T* operator * () const noexcept = 0;

			virtual const T* operator -> () const noexcept = 0;

			virtual IBaseConstIterator<T>& operator ++ () noexcept = 0;

			virtual std::unique_ptr<IBaseConstIterator<T>> operator ++ (int) noexcept = 0;

			virtual IBaseConstIterator<T>& operator -- () noexcept = 0;

			virtual std::unique_ptr<IBaseConstIterator<T>> operator -- (int) noexcept = 0;

			virtual bool operator == (const IBaseConstIterator<T>& iterator) const noexcept = 0;

			virtual bool operator != (const IBaseConstIterator<T>& iterator) const noexcept = 0;

			virtual ~IBaseConstIterator() = default;
		};
	}
}
