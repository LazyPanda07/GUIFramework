#pragma once

#include "pch.h"
#include "BaseComponents/BaseComponent.h"
#include "Menu/Menu.h"
#include "Interfaces/Iterators/IIterable.h"
#include "Iterators/composite_forward_iterator.h"
#include "Iterators/composite_const_forward_iterator.h"

namespace gui_framework
{
	/// @brief Base class for all windows that has children windows
	class GUI_FRAMEWORK_API BaseComposite :
		public BaseComponent,
		public interfaces::IIterable<BaseComponent, iterators::composite_forward_iterator, iterators::composite_const_forward_iterator>
	{
	protected:
		std::vector<std::unique_ptr<BaseComponent>> children;
		std::unordered_map<HMENU, Menu> popupMenus;
		std::unique_ptr<Menu> mainMenu;
		HICON largeIcon;
		HICON smallIcon;
		std::string pathToSmallIcon;
		std::string pathToLargeIcon;

	protected:
		virtual LRESULT preWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) override;

		virtual LRESULT compositeWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed);

		virtual LRESULT windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) final override;

	protected:
		virtual const std::string& getCreationType() const;

	private:
		std::vector<std::pair<std::string, json::utility::objectSmartPointer<json::utility::jsonObject>>> getChildrenStructure() const;

		virtual void addChild(BaseComponent* child) final;

	public:
		BaseComposite(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, const interfaces::IStyles& styles, BaseComponent* parent = nullptr, const std::string& windowFunctionName = "");

		virtual void removeChild(BaseComponent* child) final;

		virtual void removeComponents(const std::wstring& componentName) final;

		virtual BaseComponent* findChild(const std::wstring& windowName) const final;

		virtual BaseComponent* findChild(HWND handle) const final;

		virtual std::vector<BaseComponent*> findChildren(const std::wstring& windowName) const final;

		virtual const std::vector<std::unique_ptr<BaseComponent>>& getChildren() const final;

		/// @brief It needs to be called once
		/// @return Created main menu
		virtual std::unique_ptr<Menu>& createMainMenu(const std::wstring& menuName) final;

		/// @brief Don't call move operator with return value
		/// @return Created pop-up menu
		virtual Menu& addPopupMenu(const std::wstring& menuName) final;

		/// @brief Remove all pop-up menus with menuName
		/// @param menuName 
		virtual void removePopupMenus(const std::wstring& menuName);

		virtual bool isComposite() const final override;

		virtual const std::unique_ptr<Menu>& getMainMenu() const final;

		virtual std::unique_ptr<Menu>& getMainMenu() final;

		virtual std::vector<const Menu*> getPopupMenus() const final;

		/// @brief Set large icon(32x32) for specific window
		/// @param pathToLargeIcon 
		/// @exception FileDoesNotExist
		virtual void setLargeIcon(const std::filesystem::path& pathToLargeIcon) final;

		/// @brief Set small icon(16x16) for specific window
		/// @param pathToSmallIcon 
		/// @exception FileDoesNotExist
		virtual void setSmallIcon(const std::filesystem::path& pathToSmallIcon) final;

		virtual iterators::composite_forward_iterator begin() noexcept override;

		virtual iterators::composite_const_forward_iterator cbegin() const noexcept override;

		virtual iterators::composite_forward_iterator end() noexcept override;

		virtual iterators::composite_const_forward_iterator cend() const noexcept override;

		virtual void setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue) override;

		virtual json::JSONBuilder getStructure() const override;

		virtual ~BaseComposite();

		friend class BaseComponent;
	};
}
