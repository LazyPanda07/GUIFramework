#pragma once

#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Iterators/IBaseForwardIterator.h"

namespace gui_framework
{
	namespace iterators
	{
		/// @brief IBaseForwardIterator implementation for BaseComponent
		class GUI_FRAMEWORK_API composite_forward_iterator : public interfaces::IBaseForwardIterator<BaseComponent, composite_forward_iterator>
		{
		private:
			BaseComponent* currentComponent;
			std::stack<BaseComponent*> parents;
			std::stack<size_t> indices;

		public:
			composite_forward_iterator(BaseComponent* component) noexcept;

			BaseComponent* operator * () noexcept override;

			const BaseComponent* operator * () const noexcept override;

			BaseComponent* operator -> () noexcept override;

			const BaseComponent* operator -> () const noexcept override;

			IBaseConstForwardIterator<BaseComponent, composite_forward_iterator>& operator ++ () noexcept override;

			composite_forward_iterator operator ++ (int) noexcept override;

			bool operator == (const IBaseConstForwardIterator<BaseComponent, composite_forward_iterator>& composite_forward_iterator) const noexcept override;

			bool operator != (const IBaseConstForwardIterator<BaseComponent, composite_forward_iterator>& composite_forward_iterator) const noexcept override;

			~composite_forward_iterator() = default;
		};
	}
}
