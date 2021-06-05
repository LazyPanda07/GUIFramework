#include "pch.h"
#include "Utility.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		void unregisterClass(const wstring& className)
		{
			UnregisterClassW(className.data(), GetModuleHandleW(nullptr));
		}
	}
}
