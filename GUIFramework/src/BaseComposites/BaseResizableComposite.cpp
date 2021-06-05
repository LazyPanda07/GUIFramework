#include "pch.h"
#include "BaseResizableComposite.h"

using namespace std;

namespace gui_framework
{
	LRESULT BaseResizableComposite::preWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		isUsed = false;

		if (message == WM_SIZE && !this->getBlockResize())
		{
			isUsed = true;

			uint16_t width = LOWORD(lparam);
			uint16_t height = HIWORD(lparam);

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

		return -1;
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
}
