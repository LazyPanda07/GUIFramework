#pragma once

#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Iterators/IBaseConstForwardIterator.h"

namespace gui_framework
{
	namespace iterators
	{
		class GUI_FRAMEWORK_API const_forward_iterator : public interfaces::IBaseConstForwardIterator<BaseComponent, const_forward_iterator>
		{
		private:
			BaseComponent* currentComponent;
			std::stack<BaseComponent*> parents;
			std::stack<size_t> indices;

		public:
			const_forward_iterator(BaseComponent* component);

			const BaseComponent* operator * () const noexcept override;

			const BaseComponent* operator -> () const noexcept override;

			IBaseConstForwardIterator<BaseComponent, const_forward_iterator>& operator ++ () noexcept override;

			const_forward_iterator operator ++ (int) noexcept override;

			bool operator == (const IBaseConstForwardIterator<BaseComponent, const_forward_iterator>& forward_iterator) const noexcept override;

			bool operator != (const IBaseConstForwardIterator<BaseComponent, const_forward_iterator>& forward_iterator) const noexcept override;

			~const_forward_iterator() = default;
		};
	}
}
