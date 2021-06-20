#include "pch.h"
#include "WindowHolder.h"

#include "Exceptions/GetLastErrorException.h"

using namespace std;

namespace gui_framework
{
	WindowHolder::WindowHolder(const wstring& compositeWindowClassName, const wstring& compositeWindowName, int x, int y, uint16_t width, uint16_t height, const string& windowFunctionName, bool isAsync)
	{
		if (isAsync)
		{
			thread([&, this]()
				{
					compositeWindow = make_unique<BaseComposite>(compositeWindowClassName, compositeWindowName, utility::ComponentSettings(WS_BORDER, x, y, width, height), nullptr, windowFunctionName);

					this->runMainLoop();
				}).detach();
		}
		else
		{
			compositeWindow = make_unique<BaseComposite>(compositeWindowClassName, compositeWindowName, utility::ComponentSettings(WS_BORDER, x, y, width, height), nullptr, windowFunctionName);
		}
	}

	template<>
	BaseComposite* WindowHolder::get<BaseComposite>()
	{
		return compositeWindow.get();
	}

	template<>
	const BaseComposite* WindowHolder::get<BaseComposite>() const
	{
		return compositeWindow.get();
	}

	void WindowHolder::runMainLoop()
	{
		MSG message = {};
		int code;

		while (code = GetMessageW(&message, compositeWindow->getHandle(), NULL, NULL) > 0)
		{
			TranslateMessage(&message);

			DispatchMessageW(&message);
		}

		if (code == -1)
		{
			throw exceptions::GetLastErrorException(code);
		}
	}
}
