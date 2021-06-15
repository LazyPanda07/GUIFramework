#pragma once

#include "pch.h"

namespace gui_framework
{
	/// @brief Base class for all windows, controls, etc.
	class BaseComponent
	{
	public:
		enum class exitMode
		{
			destroyWindow,
			quit
		};

	protected:
		BaseComponent* parent;
		const std::wstring className;
		const std::wstring windowName;
		HWND handle;
		HINSTANCE module;
		uint16_t desiredWidth;
		uint16_t desiredHeight;
		int desiredX;
		int desiredY;
		exitMode mode;

	protected:
		virtual LRESULT preWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed);

	public:
		/// @param windowFunctionName Value that you pass in CREATE_DEFAULT_WINDOW_FUNCTION macro
		/// @param moduleName Executable name for finding classes
		BaseComponent(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent = nullptr, const std::string& windowFunctionName = "", const std::wstring& moduleName = L"");

		virtual bool isComposite() const;

		virtual LRESULT windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed);

		virtual LRESULT handleMessages(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) final;

		virtual bool destroyComponent() final;

		virtual bool asyncDestroyComponent() final;

		virtual void setDesiredWidth(uint16_t desiredWidth) final;

		virtual void setDesiredHeight(uint16_t desiredHeight) final;

		virtual void setDesiredX(int desiredX) final;

		virtual void setDesiredY(int desiredY) final;

		virtual void setExitMode(exitMode mode) final;

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
			if (topLevelWindow->getExitMode() == gui_framework::BaseComponent::exitMode::quit) \
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
