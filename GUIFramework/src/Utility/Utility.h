#pragma once

#include "pch.h"

namespace gui_framework
{
	namespace utility
	{
		void unregisterClass(const std::wstring& className);

		void appendStyle(HWND handle, LONG_PTR newStyle);

		void removeStyle(HWND handle, LONG_PTR styleToRemove);
	}
}
