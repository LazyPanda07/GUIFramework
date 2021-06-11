#pragma once

#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Iterators/IBaseIterator.h"

namespace gui_framework
{
	namespace iterators
	{
		class iterator : public interfaces::IBaseIterator<BaseComponent, iterator>
		{
		private:
			BaseComponent* currentComponent;
			std::stack<BaseComponent*> parents;
			std::stack<size_t> indices;

		public:
			iterator(BaseComponent* component);

			BaseComponent* operator * () noexcept override;

			const BaseComponent* operator * () const noexcept override;

			BaseComponent* operator -> () noexcept override;

			const BaseComponent* operator -> () const noexcept override;

			IBaseConstIterator<BaseComponent, iterator>& operator ++ () noexcept override;

			iterator operator ++ (int) noexcept override;

			IBaseConstIterator<BaseComponent, iterator>& operator -- () noexcept override;

			iterator operator -- (int) noexcept override;

			bool operator == (const IBaseConstIterator<BaseComponent, iterator>& iterator) const noexcept override;

			bool operator != (const IBaseConstIterator<BaseComponent, iterator>& iterator) const noexcept override;

			~iterator() = default;
		};
	}
}
