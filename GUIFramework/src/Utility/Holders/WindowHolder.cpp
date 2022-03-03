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
		DWORD currentThreadId = GetCurrentThreadId();

		while (code = GetMessageW(&message, nullptr, NULL, NULL) > 0)
		{
			TranslateMessage(&message);

			DispatchMessageW(&message);

			if (message.message == WM_KEYDOWN)
			{
				instance.processHotkeys();
			}

			if (currentThreadId == instance.mainThreadId)
			{
				lock_guard<recursive_mutex> runOnUIThreadLock(instance.runOnUIThreadMutex);
				queue<function<void()>>& runOnUIFunctions = instance.runOnUIFunctions;

				while (runOnUIFunctions.size())
				{
					function<void()>& currentFunction = runOnUIFunctions.front();
					function<void()>* functionWrapper = new function<void()>();

					(*functionWrapper) = [currentFunction, functionWrapper]()
					{
						currentFunction();

						delete functionWrapper;
					};

					runOnUIFunctions.pop();

					PostThreadMessageW(currentThreadId, custom_window_messages::runOnUIThreadFunctions, reinterpret_cast<WPARAM>(functionWrapper), NULL);
				}
			}
		}

		for (const auto& hotkeyId : registeredHotkeyIds)
		{
			instance.unregisterHotkey(hotkeyId);
		}

		if (code == -1)
		{
			throw exceptions::GetLastErrorException(code, __FILE__, __FUNCTION__, __LINE__);
		}

		return static_cast<int>(message.wParam);
	}

	WindowHolder::~WindowHolder()
	{
		if (unregisterClass)
		{
			utility::unregisterClass(compositeWindow->getClassName());
		}
	}
}
