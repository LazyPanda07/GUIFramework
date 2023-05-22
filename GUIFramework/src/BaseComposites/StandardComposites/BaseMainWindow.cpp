#include "BaseMainWindow.h"

#include "GUIFramework.h"

using namespace std;

namespace gui_framework
{
	LRESULT BaseMainWindow::windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		LRESULT result = BaseSeparateWindow::windowMessagesHandle(handle, message, wparam, lparam, isUsed);

		if (isUsed)
		{
			return result;
		}

		if (message == trayId)
		{
			switch (LOWORD(lparam))
			{
			case NIN_SELECT:
				isUsed = true;

				if (++clicks == 2)
				{
					Shell_NotifyIconW(NIM_DELETE, &tray);

					show();

					clicks = 0;
				}

				break;

			case WM_CONTEXTMENU:
				// TODO: RMB menu

				break;

			default:
				break;
			}
		}

		return -1;
	}

	BaseMainWindow::BaseMainWindow(const wstring& className, const wstring& titleName, const utility::ComponentSettings& settings, const string& windowFunctionName, uint16_t trayIconResource, bool maximize, bool minimize, const string& moduleName, uint16_t smallIconResource, uint16_t largeIconResource) :
		BaseSeparateWindow
		(
			className,
			titleName,
			settings,
			windowFunctionName,
			maximize,
			minimize,
			moduleName,
			smallIconResource,
			largeIconResource
		),
		clicks(0),
		trayId(GUIFramework::get().generateTrayId())
	{
		tray.cbSize = sizeof(tray);
		tray.hWnd = getHandle();
		tray.uFlags = NIF_MESSAGE | NIF_ICON;
		tray.uCallbackMessage = trayId;
		tray.uVersion = NOTIFYICON_VERSION_4;

		this->setExitMode(exitMode::quit);

		this->setOnClose
		(
			[this]()
			{
				Shell_NotifyIconW(NIM_ADD, &tray);

				Shell_NotifyIconW(NIM_SETVERSION, &tray);

				hide();

				return false;
			}
		);

		this->setOnDestroy([this]() { Shell_NotifyIconW(NIM_DELETE, &tray); });

		if (trayIconResource)
		{
			LoadIconMetric(GetModuleHandleW(nullptr), MAKEINTRESOURCE(trayIconResource), _LI_METRIC::LIM_LARGE, &tray.hIcon);
		}
	}

	size_t BaseMainWindow::getHash() const
	{
		return typeid(BaseMainWindow).hash_code();
	}
}
