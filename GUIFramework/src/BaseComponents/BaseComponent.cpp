#include "pch.h"
#include "BaseComponent.h"

#include "Exceptions/AlreadyRegisteredClassNameException.h"
#include "Exceptions/CantFindSeparateWindowFunctionException.h"

#pragma warning(disable: 6387)

using namespace std;

namespace gui_framework
{
	BaseComponent::BaseComponent(const wstring& className, const wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent, const string& windowFunctionName, const std::wstring& moduleName) :
		parent(parent),
		className(className),
		windowName(windowName),
		handle(nullptr),
		module(GetModuleHandleW(moduleName.data()))
	{
		WNDCLASSEXW classStruct = {};

		if (!GetClassInfoExW(module, className.data(), &classStruct))
		{
			if (windowFunctionName.size())
			{
				WNDPROC windowFunction = reinterpret_cast<WNDPROC>(GetProcAddress(nullptr, (windowFunctionName + "WindowFunction").data()));

				if (!windowFunction)
				{
					throw exceptions::CantFindSeparateWindowFunctionException(windowFunctionName + "WindowFunction");
				}

				classStruct.cbSize = sizeof(WNDCLASSEXW);
				classStruct.lpszClassName = className.data();
				classStruct.hInstance = module;
				classStruct.lpfnWndProc = windowFunction;
				classStruct.hbrBackground = HBRUSH(COLOR_WINDOW);

				RegisterClassExW(&classStruct);
			}
		}
		else
		{
			if (windowFunctionName.size())
			{
				throw exceptions::AlreadyRegisteredClassNameException();
			}
		}

		handle = CreateWindowExW
		(
			settings.extendedStyles,
			className.data(),
			windowName.data(),
			settings.styles | (parent ? WS_CHILDWINDOW : WS_OVERLAPPEDWINDOW),
			settings.x,
			settings.y,
			settings.width,
			settings.height,
			parent ? parent->handle : nullptr,
			nullptr,
			GetModuleHandleW(nullptr),
			nullptr
		);

		SendMessageW(handle, custom_window_messages::initTopLevelWindowPointer, reinterpret_cast<WPARAM>(this), NULL);

		ShowWindow(handle, SW_SHOW);
	}

	bool BaseComponent::isComposite() const
	{
		return false;
	}

	LRESULT BaseComponent::windowMessagesHandle(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		return DefWindowProcW(handle, msg, wparam, lparam);
	}

	BaseComponent* BaseComponent::getParent() const
	{
		return parent;
	}

	BaseComponent::~BaseComponent()
	{
		DestroyWindow(handle);
	}
}
