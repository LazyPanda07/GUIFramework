#include "pch.h"
#include "loadable_const_forward_iterator.h"

using namespace std;

namespace gui_framework
{
	namespace iterators
	{
		const filesystem::path* loadable_const_forward_iterator::operator * () const noexcept
		{
			return new filesystem::path();
		}

		const filesystem::path* loadable_const_forward_iterator::operator -> () const noexcept
		{
			return new filesystem::path();
		}

		loadable_const_forward_iterator& loadable_const_forward_iterator::operator ++ () noexcept
		{
			return *this;
		}

		loadable_const_forward_iterator loadable_const_forward_iterator::operator ++ (int) noexcept
		{
			return *this;
		}

		bool loadable_const_forward_iterator::operator == (const interfaces::IBaseConstForwardIterator<filesystem::path, loadable_const_forward_iterator>& loadable_const_forward_iterator) const noexcept
		{
			return false;
		}

		bool loadable_const_forward_iterator::operator != (const interfaces::IBaseConstForwardIterator<filesystem::path, loadable_const_forward_iterator>& loadable_const_forward_iterator) const noexcept
		{
			return false;
		}
	}
}
