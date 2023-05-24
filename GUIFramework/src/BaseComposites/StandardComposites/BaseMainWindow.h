#pragma once

#include "BaseSeparateWindow.h"

namespace gui_framework
{
	/**
	 * @brief Setup for main application window
	*/
	class GUI_FRAMEWORK_API BaseMainWindow : public BaseSeparateWindow
	{
	public:
		struct Function
		{
			std::function<void()> callable;
			std::string functionName;
			std::string moduleName;

			Function(const std::function<void()>& callable);

			Function(const std::string& functionName, const std::string& moduleName);

			~Function() = default;
		};

	private:
		NOTIFYICONDATAW tray;
		HMENU trayPopupMenu;
		uint32_t trayId;
		std::vector<std::pair<uint32_t, Function>> popupMenuItems;
		int clicks;
		uint16_t trayIconResource;
		bool alwaysShowTrayIcon;

	protected:
		virtual void onDestroyEvent();

		virtual LRESULT windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) override;

	public:
		/**
		 * @param trayIconResource Integer value from auto generated Visual Studio resources. May be NULL if no tray icon
		 * @param moduleName Name of loaded resource module with icons
		 * @param smallIconResource Integer value from auto generated Visual Studio resources
		 * @param largeIconResource Integer value from auto generated Visual Studio resources
		*/
		BaseMainWindow(const std::wstring& className, const std::wstring& titleName, const utility::ComponentSettings& settings, const std::string& windowFunctionName, uint16_t trayIconResource, bool alwaysShowTray = false, bool maximize = false, bool minimize = false, const std::string& moduleName = "", uint16_t smallIconResource = NULL, uint16_t largeIconResource = NULL);

		void initTray(uint16_t trayIconResource, bool alwaysShowTrayIcon);

		/**
		 * @brief Add tray menu text item. Works only if non NULL value passed in trayIconResource in contructor
		*/
		bool addTrayMenuItem(const std::wstring& text, const std::function<void()>& onClick);

		/**
		 * @brief Add tray menu text item. Works only if non NULL value passed in trayIconResource in contructor
		*/
		bool addTrayMenuItem(const std::wstring& text, const std::string& functionName, const std::string& moduleName);

		/**
		 * @brief Remove tray menu text item
		*/
		bool removeTrayMenuItem(const std::wstring& text);

		virtual size_t getHash() const override;

		virtual json::JSONBuilder getStructure() const override;

		virtual ~BaseMainWindow();
	};
}
