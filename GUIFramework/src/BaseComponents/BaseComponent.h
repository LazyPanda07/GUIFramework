#pragma once

#include "pch.h"
#include "Menu/Menu.h"
#include "Utility/Holders/LoadableHolders/IconsHolder.h"
#include "Interfaces/Styles/IStyles.h"
#include "Interfaces/Utility/ISerializable.h"

namespace gui_framework
{
	/// @brief Base class for all windows, controls, etc.
	class GUI_FRAMEWORK_API BaseComponent : public interfaces::ISerializable
	{
	public:
		enum class exitMode
		{
			destroyWindow,
			quit
		};

	public:
		/// @brief Add task to thread pool
		/// @param callable Function to call async
		/// @param callback Function to call after callable invokes
		static void runFunctionAsync(const std::function<void()>& callable, const std::function<void()>& callback = nullptr) noexcept;

		/// @brief Add task to thread pool
		/// @param callable Function to call async
		/// @param callback Function to call after callable invokes
		static void runFunctionAsync(std::function<void()>&& callable, const std::function<void()>& callback = nullptr) noexcept;

	protected:
		BaseComponent* parent;
		std::unordered_map<HMENU, Menu> popupMenus;
		std::unique_ptr<Menu> mainMenu;
		const std::wstring className;
		const std::wstring windowName;
		HWND handle;
		HINSTANCE module;
		uint16_t desiredWidth;
		uint16_t desiredHeight;
		int desiredX;
		int desiredY;
		exitMode mode;
		HICON largeIcon;
		HICON smallIcon;
		std::string pathToSmallIcon;
		std::string pathToLargeIcon;
		uint32_t id;
		COLORREF backgroundColor;
		COLORREF textColor;

	protected:
		virtual LRESULT preWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed);

	public:
		/// @param windowFunctionName Value that you pass in CREATE_DEFAULT_WINDOW_FUNCTION macro
		/// @param moduleName Executable name for finding classes
		BaseComponent(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, const interfaces::IStyles& styles, BaseComponent* parent = nullptr, const std::string& windowFunctionName = "", const std::wstring& moduleName = L"");

		virtual bool isComposite() const;

		virtual LRESULT windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed);

		virtual LRESULT handleMessages(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) final;

		virtual bool destroyComponent() final;

		virtual bool asyncDestroyComponent() final;

		/// @brief It needs to be called once
		/// @return Created main menu
		virtual std::unique_ptr<Menu>& createMainMenu(const std::wstring& menuName) final;

		/// @brief Don't call move operator with return value
		/// @return Created pop-up menu
		virtual Menu& addPopupMenu(const std::wstring& menuName) final;

		/// @brief Remove all pop-up menus with menuName
		/// @param menuName 
		virtual void removePopupMenus(const std::wstring& menuName);

		virtual void setDesiredWidth(uint16_t desiredWidth) final;

		virtual void setDesiredHeight(uint16_t desiredHeight) final;

		virtual void setDesiredX(int desiredX) final;

		virtual void setDesiredY(int desiredY) final;

		virtual void setExitMode(exitMode mode) final;

		/// @brief Set large icon(32x32) for specific window
		/// @param pathToLargeIcon 
		/// @exception FileDoesNotExist
		virtual void setLargeIcon(const std::filesystem::path& pathToLargeIcon) final;

		/// @brief Set small icon(16x16) for specific window
		/// @param pathToSmallIcon 
		/// @exception FileDoesNotExist
		virtual void setSmallIcon(const std::filesystem::path& pathToSmallIcon) final;

		virtual void setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue);

		virtual void setTextColor(uint8_t red, uint8_t green, uint8_t blue);

		virtual BaseComponent* getParent() const final;

		virtual HWND getHandle() const final;

		virtual const std::wstring& getWindowName() const final;

		virtual const std::wstring& getClassName() const final;

		virtual uint16_t getDesiredWidth() const final;

		virtual uint16_t getDesiredHeight() const final;

		virtual uint16_t getActualWidth() const final;

		virtual uint16_t getActualHeight() const final;
		
		virtual RECT getActualCoordinates() const final;

		virtual int getDesiredX() const final;

		virtual int getDesiredY() const final;

		virtual exitMode getExitMode() const final;

		virtual const std::unique_ptr<Menu>& getMainMenu() const final;

		virtual std::unique_ptr<Menu>& getMainMenu() final;

		virtual std::vector<const Menu*> getPopupMenus() const final;

		/// @brief 
		/// @return Components returns id, composites returns 0 
		virtual uint32_t getId() const final;

		virtual COLORREF getBackgroundColor() const final;

		virtual COLORREF getTextColor() const final;

		virtual json::JSONBuilder getStructure(json::JSONBuilder* parentStructure = nullptr) const override;
		
		virtual ~BaseComponent();
	};
}

#define CREATE_DEFAULT_WINDOW_FUNCTION(className) extern "C" __declspec(dllexport) LRESULT className##WindowFunction (HWND handle, UINT message, WPARAM wparam, LPARAM lparam)  \
{ \
	static gui_framework::BaseComponent* topLevelWindow = nullptr; \
	\
	switch(message) \
	{ \
	case WM_DESTROY: \
		if(topLevelWindow) \
		{ \
			if (topLevelWindow->getHandle() == handle && topLevelWindow->getExitMode() == gui_framework::BaseComponent::exitMode::quit) \
			{ \
				PostQuitMessage(0); \
			} \
		} \
		else \
		{ \
			PostQuitMessage(0); \
		} \
			\
		return 0; \
		\
	case gui_framework::custom_window_messages::initTopLevelWindowPointer: \
		topLevelWindow = reinterpret_cast<gui_framework::BaseComponent*>(wparam); \
			\
		return 0; \
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
