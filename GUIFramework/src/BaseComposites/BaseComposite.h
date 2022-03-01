#pragma once

#include "headers.h"
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
	public:
		enum class exitMode
		{
			destroyWindow,
			quit
		};

	protected:
		std::string windowFunctionName;
		exitMode mode;
		std::vector<std::unique_ptr<BaseComponent>> children;
		std::unordered_map<HMENU, Menu> popupMenus;
		std::unique_ptr<Menu> mainMenu;
		std::function<void()> onDestroy;
		std::string onDestroyFunctionName;
		std::string onDestroyFunctionModuleName;

	protected:
		virtual LRESULT preWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) override;

		virtual LRESULT compositeWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed);

		virtual LRESULT windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) final override;

	private:
		std::vector<std::pair<std::string, json::utility::jsonObject>> getChildrenStructure() const;

		virtual void addChild(BaseComponent* child) final;

	public:
		/// @brief 
		/// @param moduleName Name of loaded resource module with icons
		/// @param smallIconResource Integer value from auto generated Visual Studio resources
		/// @param largeIconResource Integer value from auto generated Visual Studio resources
		BaseComposite(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, const interfaces::IStyles& styles, BaseComponent* parent = nullptr, const std::string& windowFunctionName = "", const std::string& moduleName = "", uint16_t smallIconResource = NULL, uint16_t largeIconResource = NULL);

		virtual void removeChild(BaseComponent* child) final;

		virtual void removeComponents(const std::wstring& componentName) final;

		virtual BaseComponent* findChild(const std::wstring& windowName) const final;

		virtual BaseComponent* findChild(HWND handle) const final;

		virtual std::vector<BaseComponent*> findChildren(const std::wstring& windowName) const final;

		/// @brief It needs to be called once
		/// @return Created main menu
		virtual std::unique_ptr<Menu>& createMainMenu(const std::wstring& menuName);

		/// @brief Don't call move operator with return value
		/// @return Created pop-up menu
		virtual Menu& addPopupMenu(const std::wstring& menuName);

		/// @brief Remove all pop-up menus with menuName
		/// @param menuName 
		virtual void removePopupMenus(const std::wstring& menuName);

		virtual bool isComposite() const final override;

		virtual void setExitMode(exitMode mode) final;

		virtual void setOnDestroy(const std::function<void()>& onDestroy) final;

		/// @brief Load function from module. Can be seriazlied
		/// @param onDestroyFunctionName 
		/// @param onDestroyFunctionModuleName 
		/// @exception CantFindFunctionFromModuleException 
		/// @exception std::out_of_range Can't find moduleName in loaded modules
		virtual void setOnDestroy(const std::string& onDestroyFunctionName, const std::string& onDestroyFunctionModuleName) final;

		virtual exitMode getExitMode() const final;

		virtual const std::vector<std::unique_ptr<BaseComponent>>& getChildren() const final;

		virtual const std::unique_ptr<Menu>& getMainMenu() const final;

		virtual std::unique_ptr<Menu>& getMainMenu() final;

		virtual std::vector<const Menu*> getPopupMenus() const final;

		virtual const std::function<void()>& getOnDestroy() const final;

		/// @brief Used as key in creators
		/// @return typeid().hash_code() 
		virtual size_t getHash() const override = 0;

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

#define CREATE_DEFAULT_WINDOW_FUNCTION(className) extern "C" __declspec(dllexport) LRESULT className##WindowFunction(HWND handle, UINT message, WPARAM wparam, LPARAM lparam)  \
{ \
	static gui_framework::BaseComposite* topLevelWindow = nullptr; \
	\
	switch(message) \
	{ \
	case WM_CLOSE:	\
		if (topLevelWindow && (topLevelWindow->getHandle() == handle && topLevelWindow->getExitMode() == gui_framework::BaseComposite::exitMode::quit)) \
		{	\
			if (gui_framework::__utility::useOnClose(topLevelWindow))	\
			{	\
				DestroyWindow(handle);	\
			}	\
				\
			return 0;	\
		} \
		else \
		{ \
			return DefWindowProcW(handle, message, wparam, lparam); \
		} \
			\
	case WM_DESTROY: \
		if (topLevelWindow) \
		{ \
			topLevelWindow->getOnDestroy()();	\
				\
			if (topLevelWindow->getHandle() == handle && topLevelWindow->getExitMode() == gui_framework::BaseComposite::exitMode::quit) \
			{	\
				PostQuitMessage(0); \
			}	\
				\
			return 0;	\
		} \
		else \
		{ \
			return DefWindowProcW(handle, message, wparam, lparam); \
		} \
			\
	case gui_framework::custom_window_messages::initTopLevelWindowPointer: \
		topLevelWindow = reinterpret_cast<gui_framework::BaseComposite*>(wparam); \
			\
		return 0; \
			\
	case gui_framework::custom_window_messages::deinitTopLevelWindowPointer: \
		topLevelWindow = nullptr; \
			\
		return 0; \
			\
	} \
			\
	if (topLevelWindow) \
	{ \
		bool isUsed = false; \
			\
		LRESULT result = topLevelWindow->handleMessages(handle, message, wparam, lparam, isUsed); \
			\
		return isUsed ? \
			result : \
			DefWindowProcW(handle, message, wparam, lparam); \
	} \
	else \
	{ \
		return DefWindowProcW(handle, message, wparam, lparam); \
	} \
}
