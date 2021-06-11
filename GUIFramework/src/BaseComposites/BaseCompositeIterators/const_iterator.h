#pragma once

#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Iterators/IBaseConstIterator.h"

namespace gui_framework
{
	namespace iterators
	{
		class const_iterator : public interfaces::IBaseConstIterator<BaseComponent>
		{
		private:
			BaseComponent* currentComponent;
			std::stack<BaseComponent*> parents;
			std::stack<size_t> indices;

		public:
			const_iterator(BaseComponent* component);

			const BaseComponent* operator * () const noexcept override;

			const BaseComponent* operator -> () const noexcept override;

			IBaseConstIterator<BaseComponent>& operator ++ () noexcept override;

			std::unique_ptr<IBaseConstIterator<BaseComponent>> operator ++ (int) noexcept override;

			IBaseConstIterator<BaseComponent>& operator -- () noexcept override;

			std::unique_ptr<IBaseConstIterator<BaseComponent>> operator -- (int) noexcept override;

			bool operator == (const IBaseConstIterator<BaseComponent>& iterator) const noexcept override;

			bool operator != (const IBaseConstIterator<BaseComponent>& iterator) const noexcept override;

			~const_iterator() = default;
		};
	}
}
