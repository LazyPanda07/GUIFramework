#include "pch.h"
#include "const_iterator.h"

#include "IteratorsFunctionality.h"

using namespace std;

namespace gui_framework
{
	namespace iterators
	{
		const_iterator::const_iterator(BaseComponent* component) :
			currentComponent(component)
		{

		}

		const BaseComponent* const_iterator::operator * () const noexcept
		{
			return currentComponent;
		}

		const BaseComponent* const_iterator::operator -> () const noexcept
		{
			return currentComponent;
		}

		interfaces::IBaseConstIterator<BaseComponent, const_iterator>& const_iterator::operator ++ () noexcept
		{
			utility::getNextComponent(currentComponent, parents, indices);

			return *this;
		}

		const_iterator const_iterator::operator ++ (int) noexcept
		{
			const_iterator tem(*this);

			utility::getNextComponent(currentComponent, parents, indices);

			return tem;
		}

		interfaces::IBaseConstIterator<BaseComponent, const_iterator>& const_iterator::operator -- () noexcept
		{
			utility::getPreviousComponent(currentComponent, parents, indices);

			return *this;
		}

		const_iterator const_iterator::operator -- (int) noexcept
		{
			const_iterator tem(*this);

			utility::getPreviousComponent(currentComponent, parents, indices);

			return tem;
		}

		bool const_iterator::operator == (const IBaseConstIterator<BaseComponent, const_iterator>& iterator) const noexcept
		{
			return currentComponent == *iterator;
		}

		bool const_iterator::operator != (const IBaseConstIterator<BaseComponent, const_iterator>& iterator) const noexcept
		{
			return currentComponent != *iterator;
		}
	}
}
