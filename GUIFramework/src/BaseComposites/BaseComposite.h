#pragma once

#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Iterators/IIterable.h"
#include "BaseCompositeIterators/iterator.h"
#include "BaseCompositeIterators/const_iterator.h"

namespace gui_framework
{
	/// @brief Base class for all windows that has children windows
	class BaseComposite :
		public BaseComponent,
		public interfaces::IIterable<BaseComponent, iterators::iterator, iterators::const_iterator>
	{
	protected:
		std::vector<std::unique_ptr<BaseComponent>> children;

	public:
		BaseComposite(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent = nullptr, const std::string& windowFunctionName = "");

		/// @brief Add child window
		/// @param child BaseComposite takes control for all children
		virtual void addChild(BaseComponent* child) final;

		virtual void removeChild(BaseComponent* child) final;

		virtual void removeComponents(const std::wstring& componentName) final;

		virtual BaseComponent* findChild(const std::wstring& windowName) const final;

		virtual std::vector<BaseComponent*> findChildren(const std::wstring& windowName) const final;

		virtual const std::vector<std::unique_ptr<BaseComponent>>& getChildren() const final;

		virtual LRESULT compositeWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed);

		virtual LRESULT windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) final override;

		virtual bool isComposite() const final override;

		virtual iterators::iterator begin() noexcept override;

		virtual iterators::const_iterator cbegin() const noexcept override;

		virtual iterators::iterator end() noexcept override;

		virtual iterators::const_iterator cend() const noexcept override;

		virtual ~BaseComposite();
	};
}
