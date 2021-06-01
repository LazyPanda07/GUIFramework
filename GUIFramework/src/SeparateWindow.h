#pragma once

#include "pch.h"

namespace gui_framework
{
	class SeparateWindow
	{
	protected:
		HWND handle;
		const std::wstring className;
		const std::wstring titleName;
		bool unregisterAfterDestroy;
		HINSTANCE module;

	public:
		/// @brief Create new separate window
		/// @exception gui_framework::exceptions::AlreadyRegisteredClassNameException
		SeparateWindow(const std::wstring& className, const std::wstring& titleName, int x, int y, int width, int height, int showMode = SW_SHOW, bool unregisterAfterDestroy = false);

		virtual LRESULT windowMessagesHandle(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam);

		~SeparateWindow();
	};
}
