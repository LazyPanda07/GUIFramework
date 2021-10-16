#pragma once

#include "headers.h"
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
		const std::wstring className;
		const std::wstring windowName;
		HWND handle;
		uint16_t desiredWidth;
		uint16_t desiredHeight;
		int desiredX;
		int desiredY;
		exitMode mode;
		uint32_t id;
		COLORREF backgroundColor;
		COLORREF textColor;
		smartPointerType<interfaces::IStyles> styles;

	protected:
		virtual LRESULT preWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed);

		virtual LRESULT windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed);

	public:
		/// @brief 
		/// @param windowFunctionName Value that you pass in CREATE_DEFAULT_WINDOW_FUNCTION macro
		/// @param moduleName Name of loaded resource module with icons
		/// @param smallIconResource Integer value from auto generated Visual Studio resources
		/// @param largeIconResource Integer value from auto generated Visual Studio resources
		BaseComponent(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, const interfaces::IStyles& styles, BaseComponent* parent = nullptr, const std::string& windowFunctionName = "", const std::string& moduleName = "", uint16_t smallIconResource = NULL, uint16_t largeIconResource = NULL);

		virtual bool isComposite() const;

		virtual LRESULT handleMessages(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) final;

		virtual bool destroyComponent() final;

		virtual bool asyncDestroyComponent() final;

		virtual void setDesiredWidth(uint16_t desiredWidth) final;

		virtual void setDesiredHeight(uint16_t desiredHeight) final;

		virtual void setDesiredX(int desiredX) final;

		virtual void setDesiredY(int desiredY) final;

		virtual void setExitMode(exitMode mode) final;

		virtual void setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue);

		virtual void setTextColor(uint8_t red, uint8_t green, uint8_t blue);

		virtual void setStyles(interfaces::IStyles& styles) final;

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

		/// @brief 
		/// @return Components returns id, composites returns 0 
		virtual uint32_t getId() const final;

		virtual COLORREF getBackgroundColor() const final;

		virtual COLORREF getTextColor() const final;

		virtual const smartPointerType<interfaces::IStyles>& getStyles() const final;

		/// @brief Used as key in creators
		/// @return typeid().hash_code()
		virtual size_t getHash() const = 0;

		virtual json::JSONBuilder getStructure() const override;
		
		virtual ~BaseComponent();

		friend class BaseComposite;
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
			return DefWindowProcW(handle, message, wparam, lparam); \
		} \
			\
		return 0; \
		\
	case gui_framework::custom_window_messages::initTopLevelWindowPointer: \
		topLevelWindow = reinterpret_cast<gui_framework::BaseComponent*>(wparam); \
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
