#include "pch.h"
#include "WindowHolder.h"

#include "Exceptions/GetLastErrorException.h"

using namespace std;

namespace gui_framework
{
	WindowHolder::WindowHolder(unique_ptr<BaseComposite>&& compositeWindow, bool unregisterClass) noexcept :
		compositeWindow(move(compositeWindow)),
		unregisterClass(unregisterClass)
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

	void WindowHolder::runMainLoop(const vector<uint32_t>& registeredHotkeyIds)
	{
		MSG message = {};
		int code;

		while (code = GetMessageW(&message, nullptr, NULL, NULL) > 0)
		{
			if (message.message == WM_HOTKEY && message.wParam >= 0)
			{
				GUIFramework::get().processHotkey(static_cast<uint32_t>(message.wParam));
			}

			TranslateMessage(&message);

			DispatchMessageW(&message);
		}

		GUIFramework& instance = GUIFramework::get();

		for (const auto& i : registeredHotkeyIds)
		{
			instance.unregisterHotkey(i);
		}

		if (code == -1)
		{
			throw exceptions::GetLastErrorException(code);
		}
	}

	WindowHolder::~WindowHolder()
	{
		if (unregisterClass)
		{
			utility::unregisterClass(compositeWindow->getClassName());
		}
	}
}
