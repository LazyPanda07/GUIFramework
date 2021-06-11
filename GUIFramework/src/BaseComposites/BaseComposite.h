#pragma once

#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Iterators/IIterable.h"

namespace gui_framework
{
	/// @brief Base class for all windows that has children windows
	class BaseComposite :
		public BaseComponent,
		public interfaces::IIterable<BaseComponent>
	{
	public:
		class iterator : public interfaces::IBaseIterator<BaseComponent>
		{
		private:
			BaseComponent* currentComponent;
			std::stack<BaseComposite*> parents;
			std::stack<size_t> indices;

		public:
			iterator(BaseComponent* component);

			BaseComponent* operator * () noexcept override;

			const BaseComponent* operator * () const noexcept override;

			BaseComponent* operator -> () noexcept override;

			const BaseComponent* operator -> () const noexcept override;

			IBaseConstIterator<BaseComponent>& operator ++ () noexcept override;

			std::unique_ptr<IBaseConstIterator<BaseComponent>> operator ++ (int) noexcept override;

			IBaseConstIterator<BaseComponent>& operator -- () noexcept override;

			std::unique_ptr<IBaseConstIterator<BaseComponent>> operator -- (int) noexcept override;

			bool operator == (const IBaseConstIterator<BaseComponent>& iterator) const noexcept override;

			bool operator != (const IBaseConstIterator<BaseComponent>& iterator) const noexcept override;

			~iterator() = default;
		};

		class const_iterator : public interfaces::IBaseConstIterator<BaseComponent>
		{
		private:
			BaseComponent* currentComponent;
			std::stack<BaseComposite*> parents;
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

		virtual std::unique_ptr<interfaces::IBaseIterator<BaseComponent>> begin() noexcept override;

		virtual std::unique_ptr<interfaces::IBaseConstIterator<BaseComponent>> cbegin() const noexcept override;

		virtual std::unique_ptr<interfaces::IBaseIterator<BaseComponent>> end() noexcept override;

		virtual std::unique_ptr<interfaces::IBaseConstIterator<BaseComponent>> cend() const noexcept override;

		virtual ~BaseComposite();
	};
}
