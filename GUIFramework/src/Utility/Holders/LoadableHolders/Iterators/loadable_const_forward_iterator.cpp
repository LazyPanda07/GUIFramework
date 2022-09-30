#include "Core.h"
#include "loadable_const_forward_iterator.h"

using namespace std;

namespace gui_framework
{
	namespace iterators
	{
		loadable_const_forward_iterator::loadable_const_forward_iterator(vector<filesystem::path>&& data, size_t index) noexcept :
			data(move(data)),
			currentIndex(index)
		{

		}

		const filesystem::path* loadable_const_forward_iterator::operator * () const noexcept
		{
			return &data[currentIndex];
		}

		const filesystem::path* loadable_const_forward_iterator::operator -> () const noexcept
		{
			return &data[currentIndex];
		}

		loadable_const_forward_iterator& loadable_const_forward_iterator::operator ++ () noexcept
		{
			currentIndex++;

			return *this;
		}

		loadable_const_forward_iterator loadable_const_forward_iterator::operator ++ (int) noexcept
		{
			loadable_const_forward_iterator tem(*this);

			currentIndex++;

			return tem;
		}

		bool loadable_const_forward_iterator::operator == (const interfaces::IBaseConstForwardIterator<filesystem::path, loadable_const_forward_iterator>& loadable_const_forward_iterator) const noexcept
		{
			return currentIndex == dynamic_cast<const iterators::loadable_const_forward_iterator&>(loadable_const_forward_iterator).currentIndex;
		}

		bool loadable_const_forward_iterator::operator != (const interfaces::IBaseConstForwardIterator<filesystem::path, loadable_const_forward_iterator>& loadable_const_forward_iterator) const noexcept
		{
			return currentIndex != dynamic_cast<const iterators::loadable_const_forward_iterator&>(loadable_const_forward_iterator).currentIndex;
		}
	}
}
