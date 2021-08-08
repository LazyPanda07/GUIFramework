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

		void appendStyle(HWND handle, LONG_PTR newStyle)
		{
			SetWindowLongPtrW
			(
				handle,
				GWL_STYLE,
				GetWindowLongPtrW(handle, GWL_STYLE) | newStyle
			);
		}

		void removeStyle(HWND handle, LONG_PTR styleToRemove)
		{
			SetWindowLongPtrW
			(
				handle,
				GWL_STYLE,
				GetWindowLongPtrW(handle, GWL_STYLE) & ~styleToRemove
			);
		}

		string to_string(const wstring& stringToConvert, uint32_t codepage)
		{
			string result;

			int size = WideCharToMultiByte
			(
				codepage,
				NULL,
				stringToConvert.data(),
				-1,
				nullptr,
				NULL,
				NULL,
				NULL
			);

			if (!size)
			{
				throw json::exceptions::WrongEncodingException();
			}

			result.resize(static_cast<size_t>(size) - 1);

			if (!WideCharToMultiByte
			(
				codepage,
				NULL,
				stringToConvert.data(),
				-1,
				result.data(),
				size,
				NULL,
				NULL
			))
			{
				throw json::exceptions::WrongEncodingException();
			}

			return result;
		}

		wstring to_wstring(const string& stringToConvert, uint32_t codepage)
		{
			wstring result;

			int size = MultiByteToWideChar
			(
				codepage,
				NULL,
				stringToConvert.data(),
				-1,
				nullptr,
				NULL
			);

			if (!size)
			{
				throw json::exceptions::WrongEncodingException();
			}

			result.resize(static_cast<size_t>(size) - 1);

			if (!MultiByteToWideChar
			(
				codepage,
				NULL,
				stringToConvert.data(),
				-1,
				result.data(),
				size
			))
			{
				throw json::exceptions::WrongEncodingException();
			}

			return result;
		}
	}
}
