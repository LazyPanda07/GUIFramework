#include "WindowHolder.h"

#include "GUIFramework.h"
#include "Exceptions/GetLastErrorException.h"
#include "BaseComposites/StandardComposites/BaseMainWindow.h"

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
		if (BaseMainWindow* mainWindow = dynamic_cast<BaseMainWindow*>(this->compositeWindow.get()))
		{
			mainWindow->createMarkup();
		}
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

		while (code = GetMessageW(&message, nullptr, NULL, NULL))
		{
			if (code == -1)
			{
				break;
			}

			TranslateMessage(&message);

			DispatchMessageW(&message);

			if (message.message == WM_KEYDOWN)
			{
				instance.processHotkeys();
			}
			else if (message.message == custom_window_messages::runOnUIThreadFunctions)
			{
				(*reinterpret_cast<std::function<void()>*>(message.wParam))();
			}

			if (currentThreadId == instance.uiThreadId)
			{
				unique_lock<recursive_mutex> runOnUIThreadLock(instance.runOnUIThreadMutex);
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

		for (uint32_t hotkeyId : registeredHotkeyIds)
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
