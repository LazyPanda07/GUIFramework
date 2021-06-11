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

		interfaces::IBaseConstIterator<BaseComponent>& iterator::operator ++ () noexcept
		{
			utility::getNextComponent(currentComponent, parents, indices);

			return *this;
		}

		unique_ptr<interfaces::IBaseConstIterator<BaseComponent>> iterator::operator ++ (int) noexcept
		{
			unique_ptr<iterator> tem(make_unique<iterator>(*this));

			utility::getNextComponent(currentComponent, parents, indices);

			return tem;
		}

		interfaces::IBaseConstIterator<BaseComponent>& iterator::operator -- () noexcept
		{
			utility::getPreviousComponent(currentComponent, parents, indices);

			return *this;
		}

		unique_ptr<interfaces::IBaseConstIterator<BaseComponent>> iterator::operator -- (int) noexcept
		{
			unique_ptr<iterator> tem(make_unique<iterator>(*this));

			utility::getPreviousComponent(currentComponent, parents, indices);

			return tem;
		}

		bool iterator::operator == (const IBaseConstIterator<BaseComponent>& iterator) const noexcept
		{
			return currentComponent == *iterator;
		}

		bool iterator::operator != (const IBaseConstIterator<BaseComponent>& iterator) const noexcept
		{
			return currentComponent != *iterator;
		}
	}
}
