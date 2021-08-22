#include "pch.h"
#include "Utility.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		GUI_FRAMEWORK_API_FUNCTION void unregisterClass(const wstring& className)
		{
			UnregisterClassW(className.data(), GetModuleHandleW(nullptr));
		}

		GUI_FRAMEWORK_API_FUNCTION void appendStyle(HWND handle, LONG_PTR newStyle)
		{
			SetWindowLongPtrW
			(
				handle,
				GWL_STYLE,
				GetWindowLongPtrW(handle, GWL_STYLE) | newStyle
			);
		}

		GUI_FRAMEWORK_API_FUNCTION void removeStyle(HWND handle, LONG_PTR styleToRemove)
		{
			SetWindowLongPtrW
			(
				handle,
				GWL_STYLE,
				GetWindowLongPtrW(handle, GWL_STYLE) & ~styleToRemove
			);
		}

		GUI_FRAMEWORK_API_FUNCTION string to_string(const wstring& stringToConvert, uint32_t codepage)
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

		GUI_FRAMEWORK_API_FUNCTION wstring to_wstring(const string& stringToConvert, uint32_t codepage)
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

		GUI_FRAMEWORK_API_FUNCTION HMODULE getCurrentModule()
		{
			return GetModuleHandleW(nullptr);
		}

		GUI_FRAMEWORK_API_FUNCTION string getStringFromRawPath(const filesystem::path& pathFromRawString)
		{
			ostringstream fixRawString;
			string fixedPath;

			fixRawString << pathFromRawString;

			fixedPath = fixRawString.str();

			erase(fixedPath, '\"');

			return fixedPath;
		}
	}

	namespace __utility
	{
		GUI_FRAMEWORK_API_FUNCTION void changeClassName(json::utility::objectSmartPointer<json::utility::jsonObject>& object, const string& className)
		{
			get<string>(ranges::find_if(object->data, [](const pair<string, json::utility::jsonObject::variantType>& value) { return value.first == "className"; })->second) = className;
		}
	}
}
