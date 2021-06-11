#pragma once

#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Iterators/IBaseConstIterator.h"

namespace gui_framework
{
	namespace iterators
	{
		class const_iterator : public interfaces::IBaseConstIterator<BaseComponent, const_iterator>
		{
		private:
			BaseComponent* currentComponent;
			std::stack<BaseComponent*> parents;
			std::stack<size_t> indices;

		public:
			const_iterator(BaseComponent* component);

			const BaseComponent* operator * () const noexcept override;

			const BaseComponent* operator -> () const noexcept override;

			IBaseConstIterator<BaseComponent, const_iterator>& operator ++ () noexcept override;

			const_iterator operator ++ (int) noexcept override;

			IBaseConstIterator<BaseComponent, const_iterator>& operator -- () noexcept override;

			const_iterator operator -- (int) noexcept override;

			bool operator == (const IBaseConstIterator<BaseComponent, const_iterator>& iterator) const noexcept override;

			bool operator != (const IBaseConstIterator<BaseComponent, const_iterator>& iterator) const noexcept override;

			~const_iterator() = default;
		};
	}
}
