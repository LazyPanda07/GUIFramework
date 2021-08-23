#pragma once

#include "headers.h"
#include "Interfaces/Iterators/IBaseConstForwardIterator.h"

namespace gui_framework
{
	namespace iterators
	{
		/// @brief IBaseConstForwardIterator implementation for BaseLoadableHolder
		class GUI_FRAMEWORK_API loadable_const_forward_iterator : public interfaces::IBaseConstForwardIterator<std::filesystem::path, loadable_const_forward_iterator>
		{
		private:
			std::vector<std::filesystem::path> data;
			size_t currentIndex;

		public:
			loadable_const_forward_iterator(std::vector<std::filesystem::path>&& data, size_t index) noexcept;

			const std::filesystem::path* operator * () const noexcept override;

			const std::filesystem::path* operator -> () const noexcept override;

			loadable_const_forward_iterator& operator ++ () noexcept override;

			loadable_const_forward_iterator operator ++ (int) noexcept override;

			bool operator == (const interfaces::IBaseConstForwardIterator<std::filesystem::path, loadable_const_forward_iterator>& loadable_const_forward_iterator) const noexcept override;

			bool operator != (const interfaces::IBaseConstForwardIterator<std::filesystem::path, loadable_const_forward_iterator>& loadable_const_forward_iterator) const noexcept override;

			~loadable_const_forward_iterator() = default;
		};
	}
}
