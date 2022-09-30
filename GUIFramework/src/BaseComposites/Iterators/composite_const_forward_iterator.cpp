#include "Core.h"
#include "composite_const_forward_iterator.h"

#include "IteratorsFunctionality.h"

using namespace std;

namespace gui_framework
{
	namespace iterators
	{
		composite_const_forward_iterator::composite_const_forward_iterator(BaseComponent* component) noexcept :
			currentComponent(component)
		{

		}

		const BaseComponent* composite_const_forward_iterator::operator * () const noexcept
		{
			return currentComponent;
		}

		const BaseComponent* composite_const_forward_iterator::operator -> () const noexcept
		{
			return currentComponent;
		}

		interfaces::IBaseConstForwardIterator<BaseComponent, composite_const_forward_iterator>& composite_const_forward_iterator::operator ++ () noexcept
		{
			utility::getNextComponent(currentComponent, parents, indices);

			return *this;
		}

		composite_const_forward_iterator composite_const_forward_iterator::operator ++ (int) noexcept
		{
			composite_const_forward_iterator tem(*this);

			utility::getNextComponent(currentComponent, parents, indices);

			return tem;
		}

		bool composite_const_forward_iterator::operator == (const IBaseConstForwardIterator<BaseComponent, composite_const_forward_iterator>& composite_forward_iterator) const noexcept
		{
			return currentComponent == *composite_forward_iterator;
		}

		bool composite_const_forward_iterator::operator != (const IBaseConstForwardIterator<BaseComponent, composite_const_forward_iterator>& composite_forward_iterator) const noexcept
		{
			return currentComponent != *composite_forward_iterator;
		}
	}
}
