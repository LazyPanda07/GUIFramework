#include "pch.h"
#include "forward_iterator.h"

#include "IteratorsFunctionality.h"

using namespace std;

namespace gui_framework
{
	namespace iterators
	{
		forward_iterator::forward_iterator(BaseComponent* component) :
			currentComponent(component)
		{

		}

		BaseComponent* forward_iterator::operator * () noexcept
		{
			return currentComponent;
		}

		const BaseComponent* forward_iterator::operator * () const noexcept
		{
			return currentComponent;
		}

		BaseComponent* forward_iterator::operator -> () noexcept
		{
			return currentComponent;
		}

		const BaseComponent* forward_iterator::operator -> () const noexcept
		{
			return currentComponent;
		}

		interfaces::IBaseConstForwardIterator<BaseComponent, forward_iterator>& forward_iterator::operator ++ () noexcept
		{
			utility::getNextComponent(currentComponent, parents, indices);

			return *this;
		}

		forward_iterator forward_iterator::operator ++ (int) noexcept
		{
			forward_iterator tem(*this);

			utility::getNextComponent(currentComponent, parents, indices);

			return tem;
		}

		bool forward_iterator::operator == (const IBaseConstForwardIterator<BaseComponent, forward_iterator>& forward_iterator) const noexcept
		{
			return currentComponent == *forward_iterator;
		}

		bool forward_iterator::operator != (const IBaseConstForwardIterator<BaseComponent, forward_iterator>& forward_iterator) const noexcept
		{
			return currentComponent != *forward_iterator;
		}
	}
}
