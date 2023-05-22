#pragma once

#include "BaseSeparateWindow.h"

namespace gui_framework
{
	/**
	 * @brief Setup for main application window
	*/
	class GUI_FRAMEWORK_API BaseMainWindow : public BaseSeparateWindow
	{
	private:
		NOTIFYICONDATAW tray;
		uint32_t trayId;
		int clicks;

	protected:
		virtual LRESULT windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) override;

	public:
		/**
		 * @param trayIconResource Integer value from auto generated Visual Studio resources. May be NULL if no tray icon
		 * @param moduleName Name of loaded resource module with icons
		 * @param smallIconResource Integer value from auto generated Visual Studio resources
		 * @param largeIconResource Integer value from auto generated Visual Studio resources
		*/
		BaseMainWindow(const std::wstring& className, const std::wstring& titleName, const utility::ComponentSettings& settings, const std::string& windowFunctionName, uint16_t trayIconResource, bool maximize = false, bool minimize = false, const std::string& moduleName = "", uint16_t smallIconResource = NULL, uint16_t largeIconResource = NULL);

		virtual size_t getHash() const override;

		virtual ~BaseMainWindow() = default;
	};
}
