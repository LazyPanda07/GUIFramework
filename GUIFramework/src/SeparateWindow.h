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

	private:
		static LRESULT windowFunction(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam);

	public:
		SeparateWindow(const std::wstring& className, const std::wstring& titleName, int x, int y, int width, int height, int showMode = SW_SHOW, bool unregisterAfterDestroy = false);

		virtual LRESULT windowMessagesHandle(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam);

		~SeparateWindow();
	};
}
