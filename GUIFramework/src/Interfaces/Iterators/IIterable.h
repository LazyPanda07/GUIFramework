#pragma once

#include "pch.h"
#include "IBaseForwardIterator.h"

namespace gui_framework
{
	namespace interfaces
	{
		/// @brief Specify iterable class
		/// @tparam T Class type
		/// @tparam TForwardIterator Forward iterator for that class
		/// @tparam TConstForwardIterator Const forward iterator for that class
		template<typename T, typename TForwardIterator, typename TConstForwardIterator> requires (std::is_base_of_v<IBaseForwardIterator<T, TForwardIterator>, TForwardIterator> && std::is_base_of_v<IBaseConstForwardIterator<T, TConstForwardIterator>, TConstForwardIterator>)
		class GUI_FRAMEWORK_API IIterable
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
