#pragma once

#include "pch.h"
#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Iterators/IBaseConstForwardIterator.h"

namespace gui_framework
{
	namespace iterators
	{
		class GUI_FRAMEWORK_API composite_const_forward_iterator : public interfaces::IBaseConstForwardIterator<BaseComponent, composite_const_forward_iterator>
		{
		private:
			BaseComponent* currentComponent;
			std::stack<BaseComponent*> parents;
			std::stack<size_t> indices;

		public:
			composite_const_forward_iterator(BaseComponent* component) noexcept;

			const BaseComponent* operator * () const noexcept override;

			const BaseComponent* operator -> () const noexcept override;

			IBaseConstForwardIterator<BaseComponent, composite_const_forward_iterator>& operator ++ () noexcept override;

			composite_const_forward_iterator operator ++ (int) noexcept override;

			bool operator == (const IBaseConstForwardIterator<BaseComponent, composite_const_forward_iterator>& composite_forward_iterator) const noexcept override;

			bool operator != (const IBaseConstForwardIterator<BaseComponent, composite_const_forward_iterator>& composite_forward_iterator) const noexcept override;

			~composite_const_forward_iterator() = default;
		};
	}
}
