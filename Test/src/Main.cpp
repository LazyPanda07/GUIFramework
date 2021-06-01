#include <iostream>

#include "Window.h"

#pragma comment (lib, "GUIFramework.lib")

using namespace std;

LRESULT function(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);

		return 0;

	default:
		return DefWindowProcW(handle, msg, wparam, lparam);
	}
}

int main(int argc, char** argv)
{
	

	return 0;
}
