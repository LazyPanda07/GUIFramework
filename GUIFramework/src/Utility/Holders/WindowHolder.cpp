#include "headers.h"
#include "WindowHolder.h"

#include "GUIFramework.h"

#include "Exceptions/GetLastErrorException.h"

using namespace std;

namespace gui_framework
{
	WindowHolder::WindowHolder(BaseDialogBox* dialogBox) :
		compositeWindow(dialogBox),
		unregisterClass(false)
	{

	}

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

	int WindowHolder::runMainLoop(const vector<uint32_t>& registeredHotkeyIds)
	{
		MSG message = {};
		int code;
		GUIFramework& instance = GUIFramework::get();
		HWND handle = compositeWindow->getHandle();

		while (code = GetMessageW(&message, handle, NULL, NULL) > 0)
		{
			TranslateMessage(&message);

			DispatchMessageW(&message);

			if (message.message == WM_KEYDOWN)
			{
				instance.processHotkeys();
			}
		}

		for (const auto& i : registeredHotkeyIds)
		{
			instance.unregisterHotkey(i);
		}

		if (code == -1)
		{
			throw exceptions::GetLastErrorException(code, __FILE__, __FUNCTION__, __LINE__);
		}

		return static_cast<int>(message.message);
	}

	WindowHolder::~WindowHolder()
	{
		if (unregisterClass)
		{
			utility::unregisterClass(compositeWindow->getClassName());
		}
	}
}
