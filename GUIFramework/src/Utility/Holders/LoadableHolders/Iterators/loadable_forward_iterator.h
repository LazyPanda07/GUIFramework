#pragma once

#include "Interfaces/Iterators/IBaseForwardIterator.h"

namespace gui_framework
{
	namespace iterators
	{
		/// @brief IBaseForwardIterator implementation for BaseLoadableHolder
		class GUI_FRAMEWORK_API loadable_forward_iterator : public interfaces::IBaseForwardIterator<std::filesystem::path, loadable_forward_iterator>
		{
		private:
			std::vector<std::filesystem::path> data;
			size_t currentIndex;

		public:
			loadable_forward_iterator(std::vector<std::filesystem::path>&& data, size_t index) noexcept;

			std::filesystem::path* operator * () noexcept override;

			const std::filesystem::path* operator * () const noexcept override;

			std::filesystem::path* operator -> () noexcept override;

			const std::filesystem::path* operator -> () const noexcept override;

			loadable_forward_iterator& operator ++ () noexcept override;

			loadable_forward_iterator operator ++ (int) noexcept override;

			bool operator == (const interfaces::IBaseConstForwardIterator<std::filesystem::path, loadable_forward_iterator>& loadable_const_forward_iterator) const noexcept override;

			bool operator != (const interfaces::IBaseConstForwardIterator<std::filesystem::path, loadable_forward_iterator>& loadable_const_forward_iterator) const noexcept override;

			~loadable_forward_iterator() = default;
		};
	}
}
