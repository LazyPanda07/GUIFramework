#include "pch.h"
#include "iterator.h"

#include "IteratorsFunctionality.h"

using namespace std;

namespace gui_framework
{
	namespace iterators
	{
		iterator::iterator(BaseComponent* component) :
			currentComponent(component)
		{

		}

		BaseComponent* iterator::operator * () noexcept
		{
			return currentComponent;
		}

		const BaseComponent* iterator::operator * () const noexcept
		{
			return currentComponent;
		}

		BaseComponent* iterator::operator -> () noexcept
		{
			return currentComponent;
		}

		const BaseComponent* iterator::operator -> () const noexcept
		{
			return currentComponent;
		}

		interfaces::IBaseConstIterator<BaseComponent, iterator>& iterator::operator ++ () noexcept
		{
			utility::getNextComponent(currentComponent, parents, indices);

			return *this;
		}

		iterator iterator::operator ++ (int) noexcept
		{
			iterator tem(*this);

			utility::getNextComponent(currentComponent, parents, indices);

			return tem;
		}

		interfaces::IBaseConstIterator<BaseComponent, iterator>& iterator::operator -- () noexcept
		{
			utility::getPreviousComponent(currentComponent, parents, indices);

			return *this;
		}

		iterator iterator::operator -- (int) noexcept
		{
			iterator tem(*this);

			utility::getPreviousComponent(currentComponent, parents, indices);

			return tem;
		}

		bool iterator::operator == (const IBaseConstIterator<BaseComponent, iterator>& iterator) const noexcept
		{
			return currentComponent == *iterator;
		}

		bool iterator::operator != (const IBaseConstIterator<BaseComponent, iterator>& iterator) const noexcept
		{
			return currentComponent != *iterator;
		}
	}
}
