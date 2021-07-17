#include "pch.h"
#include "WindowHolder.h"

#include "Exceptions/GetLastErrorException.h"

using namespace std;

namespace gui_framework
{
	WindowHolder::WindowHolder(unique_ptr<BaseComposite>&& compositeWindow) noexcept :
		compositeWindow(move(compositeWindow))
	{

	}

	BaseComposite* WindowHolder::get()
	{
		return compositeWindow.get();
	}

	const BaseComposite* WindowHolder::get() const
	{
		return compositeWindow.get();
	}

	void WindowHolder::runMainLoop()
	{
		MSG message = {};
		int code;

		while (code = GetMessageW(&message, nullptr, NULL, NULL) > 0)
		{
			if (message.message == WM_HOTKEY)
			{
				GUIFramework::get().processHotkey(message.wParam);
			}

			TranslateMessage(&message);

			DispatchMessageW(&message);
		}

		if (code == -1)
		{
			throw exceptions::GetLastErrorException(code);
		}
	}
}
