#include "pch.h"
#include "loadable_forward_iterator.h"

using namespace std;

namespace gui_framework
{
	namespace iterators
	{
		filesystem::path* loadable_forward_iterator::operator * () noexcept
		{
			return new filesystem::path();
		}

		const filesystem::path* loadable_forward_iterator::operator * () const noexcept
		{
			return new filesystem::path();
		}

		filesystem::path* loadable_forward_iterator::operator -> () noexcept
		{
			return new filesystem::path();
		}

		const filesystem::path* loadable_forward_iterator::operator -> () const noexcept
		{
			return new filesystem::path();
		}

		loadable_forward_iterator& loadable_forward_iterator::operator ++ () noexcept
		{
			return *this;
		}

		loadable_forward_iterator loadable_forward_iterator::operator ++ (int) noexcept
		{
			return *this;
		}

		bool loadable_forward_iterator::operator == (const interfaces::IBaseConstForwardIterator<filesystem::path, loadable_forward_iterator>& loadable_const_forward_iterator) const noexcept
		{
			return false;
		}

		bool loadable_forward_iterator::operator != (const interfaces::IBaseConstForwardIterator<filesystem::path, loadable_forward_iterator>& loadable_const_forward_iterator) const noexcept
		{
			return false;
		}
	}
}
