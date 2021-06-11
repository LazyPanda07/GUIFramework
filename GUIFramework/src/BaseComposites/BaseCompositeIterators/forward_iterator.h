#pragma once

#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Iterators/IBaseForwardIterator.h"

namespace gui_framework
{
	namespace iterators
	{
		class forward_iterator : public interfaces::IBaseForwardIterator<BaseComponent, forward_iterator>
		{
		private:
			BaseComponent* currentComponent;
			std::stack<BaseComponent*> parents;
			std::stack<size_t> indices;

		public:
			forward_iterator(BaseComponent* component);

			BaseComponent* operator * () noexcept override;

			const BaseComponent* operator * () const noexcept override;

			BaseComponent* operator -> () noexcept override;

			const BaseComponent* operator -> () const noexcept override;

			IBaseConstForwardIterator<BaseComponent, forward_iterator>& operator ++ () noexcept override;

			forward_iterator operator ++ (int) noexcept override;

			bool operator == (const IBaseConstForwardIterator<BaseComponent, forward_iterator>& forward_iterator) const noexcept override;

			bool operator != (const IBaseConstForwardIterator<BaseComponent, forward_iterator>& forward_iterator) const noexcept override;

			~forward_iterator() = default;
		};
	}
}
