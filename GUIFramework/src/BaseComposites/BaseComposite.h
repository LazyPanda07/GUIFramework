#pragma once

#include "pch.h"
#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Iterators/IIterable.h"
#include "BaseCompositeIterators/forward_iterator.h"
#include "BaseCompositeIterators/const_forward_iterator.h"

namespace gui_framework
{
	/// @brief Base class for all windows that has children windows
	class GUI_FRAMEWORK_API BaseComposite :
		public BaseComponent,
		public interfaces::IIterable<BaseComponent, iterators::forward_iterator, iterators::const_forward_iterator>
	{
	protected:
		std::vector<std::unique_ptr<BaseComponent>> children;

	private:
		virtual LRESULT preWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) override;

	private:
		std::vector<std::pair<std::string, json::utility::objectSmartPointer<json::utility::jsonObject>>> getChildrenStructure(json::JSONBuilder& parentStructure) const;

	protected:
		virtual json::JSONBuilder getStructure(json::JSONBuilder* parentStructure = nullptr) const override;

	public:
		BaseComposite(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, const interfaces::IStyles& styles, BaseComponent* parent = nullptr, const std::string& windowFunctionName = "");

		/// @brief BaseComponent's constructor calls this method if parent != nullptr, there is no need to explicitly call this method
		/// @param child BaseComposite takes control for all children
		virtual void addChild(BaseComponent* child) final;

		virtual void removeChild(BaseComponent* child) final;

		virtual void removeComponents(const std::wstring& componentName) final;

		virtual BaseComponent* findChild(const std::wstring& windowName) const final;

		virtual BaseComponent* findChild(HWND handle) const final;

		virtual std::vector<BaseComponent*> findChildren(const std::wstring& windowName) const final;

		virtual const std::vector<std::unique_ptr<BaseComponent>>& getChildren() const final;

		virtual LRESULT compositeWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed);

		virtual LRESULT windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) final override;

		virtual bool isComposite() const final override;

		virtual iterators::forward_iterator begin() noexcept override;

		virtual iterators::const_forward_iterator cbegin() const noexcept override;

		virtual iterators::forward_iterator end() noexcept override;

		virtual iterators::const_forward_iterator cend() const noexcept override;

		virtual void setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue) final override;

		virtual ~BaseComposite();
	};
}
