#pragma once

#include "pch.h"

namespace gui_framework
{
	class Window
	{
	private:
		HWND handle;

	public:
		Window(const std::wstring& className, const std::wstring& titleName, int x, int y, int width, int height, WNDPROC function = nullptr);

		~Window();
	};
}
