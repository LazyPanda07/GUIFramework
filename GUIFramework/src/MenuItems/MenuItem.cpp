#include "pch.h"
#include "MenuItem.h"

using namespace std;

namespace gui_framework
{
	MenuItem::MenuItem(const wstring& text, const function<void()>& onClick) :
		BaseMenuItem(text),
		onClick(onClick)
	{

	}

	void MenuItem::processMessage()
	{
		onClick();
	}
}
