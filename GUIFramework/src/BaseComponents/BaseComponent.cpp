#include "pch.h"
#include "BaseComponent.h"

#include "BaseComposites/BaseComposite.h"
#include "Exceptions/AlreadyRegisteredClassNameException.h"
#include "Exceptions/CantFindSeparateWindowFunctionException.h"
#include "Interfaces/Components/IResizableComponent.h"

#pragma warning(disable: 6387)

using namespace std;

namespace gui_framework
{
	LRESULT BaseComponent::preWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		isUsed = false;

		return -1;
	}

	BaseComponent::BaseComponent(const wstring& className, const wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent, const string& windowFunctionName, const std::wstring& moduleName) :
		parent(parent),
		className(className),
		windowName(windowName),
		handle(nullptr),
		module(GetModuleHandleW(moduleName.data())),
		desiredWidth(settings.width),
		desiredHeight(settings.height),
		desiredX(settings.x),
		desiredY(settings.y)
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
				classStruct.hCursor = LoadCursorW(module, IDC_ARROW);
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
			settings.id,
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

	LRESULT BaseComponent::windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		isUsed = false;

		return -1;
	}

	LRESULT BaseComponent::handleMessages(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		LRESULT result = this->preWindowMessagesHandle(handle, message, wparam, lparam, isUsed);
		
		if (isUsed)
		{
			return result;
		}

		return this->windowMessagesHandle(handle, message, wparam, lparam, isUsed);
	}

	bool BaseComponent::destroyComponent()
	{
		bool result = DestroyWindow(handle);

		BaseComposite* parentComposite = dynamic_cast<BaseComposite*>(parent);

		if (parentComposite)
		{
			parentComposite->removeChild(this);
		}

		return result;
	}

	bool BaseComponent::asyncDestroyComponent()
	{
		return PostMessageW(handle, WM_DESTROY, NULL, NULL);
	}

	void BaseComponent::setDesiredWidth(uint16_t desiredWidth)
	{
		this->desiredWidth = desiredWidth;
	}

	void BaseComponent::setDesiredHeight(uint16_t desiredHeight)
	{
		this->desiredHeight = desiredHeight;
	}

	void BaseComponent::setDesiredX(int desiredX)
	{
		this->desiredX = desiredX;
	}

	void BaseComponent::setDesiredY(int desiredY)
	{
		this->desiredY = desiredY;
	}

	BaseComponent* BaseComponent::getParent() const
	{
		return parent;
	}

	HWND BaseComponent::getHandle() const
	{
		return handle;
	}

	const wstring& BaseComponent::getWindowName() const
	{
		return windowName;
	}

	const wstring& BaseComponent::getClassName() const
	{
		return className;
	}

	uint16_t BaseComponent::getDesiredWidth() const
	{
		return desiredWidth;
	}

	uint16_t BaseComponent::getDesiredHeight() const
	{
		return desiredHeight;
	}

	uint16_t BaseComponent::getActualWidth() const
	{
		RECT sizes;

		GetClientRect(handle, &sizes);

		return static_cast<uint16_t>(sizes.right - sizes.left);
	}

	uint16_t BaseComponent::getActualHeight() const
	{
		RECT sizes;

		GetClientRect(handle, &sizes);

		return static_cast<uint16_t>(sizes.bottom - sizes.top);
	}

	RECT BaseComponent::getActualCoordinates() const
	{
		RECT coordinates;

		GetWindowRect(handle, &coordinates);

		MapWindowPoints(HWND_DESKTOP, parent ? parent->getHandle() : HWND_DESKTOP, reinterpret_cast<POINT*>(&coordinates), 2);

		return coordinates;
	}

	int BaseComponent::getDesiredX() const
	{
		return desiredX;
	}

	int BaseComponent::getDesiredY() const
	{
		return desiredY;
	}

	BaseComponent::~BaseComponent()
	{
		if (!this->destroyComponent())
		{
			this->asyncDestroyComponent();
		}
	}
}
