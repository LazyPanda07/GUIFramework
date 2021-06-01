#pragma once

#include "pch.h"

namespace gui_framework
{
	class BaseComponent
	{
	protected:
		BaseComponent* parent;
		const std::wstring className;
		const std::wstring windowName;
		HWND handle;
		HINSTANCE module;

	public:
		BaseComponent(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent = nullptr, const std::string& windowFunctionName = "", const std::wstring& moduleName = L"");

		virtual bool isComposite() const;

		virtual LRESULT windowMessagesHandle(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam, bool& isUsed);

		virtual BaseComponent* getParent() const final;

		virtual ~BaseComponent();
	};
}

#define CREATE_DEFAULT_WINDOW_FUNCTION(className) extern "C" __declspec(dllexport) LRESULT className##WindowFunction (HWND handle, UINT msg, WPARAM wparam, LPARAM lparam)  \
{ \
	static gui_framework::BaseComponent* topLevelWindow = nullptr; \
	\
	switch(msg) \
	{ \
	case WM_DESTROY: \
		PostQuitMessage(0); \
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
		LRESULT result = topLevelWindow->windowMessagesHandle(handle, msg, wparam, lparam, isUsed); \
			\
		return isUsed ? \
			result : \
			DefWindowProcW(handle, msg, wparam, lparam); \
	} \
	else \
	{ \
		return DefWindowProcW(handle, msg, wparam, lparam); \
	} \
}