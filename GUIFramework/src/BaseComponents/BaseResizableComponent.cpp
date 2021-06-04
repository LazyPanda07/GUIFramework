#include "pch.h"
#include "BaseResizableComponent.h"

using namespace std;

namespace gui_framework
{
	LRESULT BaseResizableComponent::preWindowMessagesHandle(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		isUsed = false;

		if (msg == WM_SIZE && !this->getBlockResize())
		{
			isUsed = true;

			this->resize(LOWORD(lparam), HIWORD(lparam));

			return 0;
		}

		return BaseComponent::preWindowMessagesHandle(handle, msg, wparam, lparam, isUsed);
	}

	BaseResizableComponent::BaseResizableComponent(const wstring& className, const wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent, const string& windowFunctionName, const wstring& moduleName) :
		BaseComponent
		(
			className,
			windowName,
			utility::ComponentSettings
			(
				settings.styles | WS_THICKFRAME,
				settings.x,
				settings.y,
				settings.width,
				settings.height,
				settings.id,
				settings.extendedStyles
			),
			parent,
			windowFunctionName,
			moduleName
		),
		IResizableComponent
		(
			handle,
			parent ? parent->getHandle() : GetDesktopWindow()
		)
	{

	}

	void BaseResizableComponent::resize(uint16_t width, uint16_t height)
	{
		SetWindowPos
		(
			handle,
			HWND_BOTTOM,
			desiredX,
			desiredY,
			desiredWidth,
			desiredHeight,
			SWP_SHOWWINDOW
		);
	}
}
