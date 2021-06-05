#include "pch.h"
#include "BaseResizableComposite.h"

using namespace std;

namespace gui_framework
{
	LRESULT BaseResizableComposite::preWindowMessagesHandle(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		if (msg == WM_SIZE)
		{
			isUsed = true;

			uint16_t width = LOWORD(lparam);
			uint16_t height = HIWORD(wparam);

			this->resize(width, height);

			for (const auto& i : children)
			{
				interfaces::IResizableComponent* resizable = dynamic_cast<interfaces::IResizableComponent*>(i.get());

				if (resizable)
				{
					resizable->resize(width, height);
				}
			}

			return 0;
		}

		return DefWindowProcW(handle, msg, wparam, lparam);
	}

	BaseResizableComposite::BaseResizableComposite(const wstring& className, const wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent, const string& windowFunctionName) :
		BaseComposite
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
			windowFunctionName
		),
		IResizableComponent
		(
			handle,
			parent ? parent->getHandle() : GetDesktopWindow()
		)
	{

	}

	void BaseResizableComposite::resize(uint16_t width, uint16_t height)
	{

	}
}
