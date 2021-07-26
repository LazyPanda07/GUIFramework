#include "pch.h"
#include "composite_forward_iterator.h"

#include "IteratorsFunctionality.h"

using namespace std;

namespace gui_framework
{
	namespace iterators
	{
		composite_forward_iterator::composite_forward_iterator(BaseComponent* component) :
			currentComponent(component)
		{

		}

		BaseComponent* composite_forward_iterator::operator * () noexcept
		{
			return currentComponent;
		}

		const BaseComponent* composite_forward_iterator::operator * () const noexcept
		{
			return currentComponent;
		}

		BaseComponent* composite_forward_iterator::operator -> () noexcept
		{
			return currentComponent;
		}

		const BaseComponent* composite_forward_iterator::operator -> () const noexcept
		{
			return currentComponent;
		}

		interfaces::IBaseConstForwardIterator<BaseComponent, composite_forward_iterator>& composite_forward_iterator::operator ++ () noexcept
		{
			utility::getNextComponent(currentComponent, parents, indices);

			return *this;
		}

		composite_forward_iterator composite_forward_iterator::operator ++ (int) noexcept
		{
			composite_forward_iterator tem(*this);

			utility::getNextComponent(currentComponent, parents, indices);

			return tem;
		}

		bool composite_forward_iterator::operator == (const IBaseConstForwardIterator<BaseComponent, composite_forward_iterator>& composite_forward_iterator) const noexcept
		{
			return currentComponent == *composite_forward_iterator;
		}

		bool composite_forward_iterator::operator != (const IBaseConstForwardIterator<BaseComponent, composite_forward_iterator>& composite_forward_iterator) const noexcept
		{
			return currentComponent != *composite_forward_iterator;
		}
	}
}
