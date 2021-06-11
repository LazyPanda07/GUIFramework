#include "pch.h"
#include "const_forward_iterator.h"

#include "IteratorsFunctionality.h"

using namespace std;

namespace gui_framework
{
	namespace iterators
	{
		const_forward_iterator::const_forward_iterator(BaseComponent* component) :
			currentComponent(component)
		{

		}

		const BaseComponent* const_forward_iterator::operator * () const noexcept
		{
			return currentComponent;
		}

		const BaseComponent* const_forward_iterator::operator -> () const noexcept
		{
			return currentComponent;
		}

		interfaces::IBaseConstForwardIterator<BaseComponent, const_forward_iterator>& const_forward_iterator::operator ++ () noexcept
		{
			utility::getNextComponent(currentComponent, parents, indices);

			return *this;
		}

		const_forward_iterator const_forward_iterator::operator ++ (int) noexcept
		{
			const_forward_iterator tem(*this);

			utility::getNextComponent(currentComponent, parents, indices);

			return tem;
		}

		bool const_forward_iterator::operator == (const IBaseConstForwardIterator<BaseComponent, const_forward_iterator>& forward_iterator) const noexcept
		{
			return currentComponent == *forward_iterator;
		}

		bool const_forward_iterator::operator != (const IBaseConstForwardIterator<BaseComponent, const_forward_iterator>& forward_iterator) const noexcept
		{
			return currentComponent != *forward_iterator;
		}
	}
}
