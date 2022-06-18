#include "headers.h"
#include "Utility.h"

#include "BaseComposites/StandardComposites/BaseSeparateWindow.h"
#include "BaseComponents/StandardComponents/BaseRichEdit.h"
#include "GUIFramework.h"

#include "Exceptions/CantFindFunctionFromModuleException.h"
#include "Exceptions/NotImplemented.h"

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

		GUI_FRAMEWORK_API_FUNCTION void loadFunctionFromModule(function<void()>& onClick, const string& functionName, const string& moduleName)
		{
			GUIFramework& instance = GUIFramework::get();
			const HMODULE& module = instance.getModules().at(moduleName);

			onClickSignature tem = reinterpret_cast<onClickSignature>(GetProcAddress(module, functionName.data()));

			if (!tem)
			{
				throw exceptions::CantFindFunctionFromModuleException(functionName, moduleName, __FILE__, __FUNCTION__, __LINE__);
			}

			onClick = tem;
		}

		GUI_FRAMEWORK_API_FUNCTION void loadEventCallbackFromModule(function<void(const wstring&)>& eventCallback, const string& functionName, const string& moduleName)
		{
			GUIFramework& instance = GUIFramework::get();
			const HMODULE& module = instance.getModules().at(moduleName);

			richEditCallbackSignature tem = reinterpret_cast<richEditCallbackSignature>(GetProcAddress(module, functionName.data()));

			if (!tem)
			{
				throw exceptions::CantFindFunctionFromModuleException(functionName, moduleName, __FILE__, __FUNCTION__, __LINE__);
			}

			eventCallback = tem;
		}

		GUI_FRAMEWORK_API_FUNCTION string getGUIFrameworkVersion()
		{
			return "0.9-beta"s;
		}
	}

	namespace __utility
	{
		GUI_FRAMEWORK_API_FUNCTION void throwNotImplementedException(string_view methodName, string_view className)
		{
			try
			{
				if (GUIFramework::get().getIsUsingNotImplementedExceptions())
				{
					throw exceptions::NotImplemented(methodName, className, __FILE__, __LINE__);
				}
			}
			catch (const json::exceptions::CantFindValueException&)
			{

			}
		}

		GUI_FRAMEWORK_API_FUNCTION string extendedException(const string& exceptionMessage, string_view fileName, string_view methodName, int line)
		{
			try
			{
				if (GUIFramework::get().getIsUsingExtendedExceptions())
				{
					return format(R"({} in file "{}" in "{}" method on {} line)"sv, exceptionMessage, fileName.substr(fileName.rfind('\\') + 1), methodName, line);
				}
			}
			catch (const json::exceptions::CantFindValueException&)
			{
				
			}

			return exceptionMessage;
		}

		GUI_FRAMEWORK_API_FUNCTION bool useOnClose(any topLevelWindow)
		{
			interfaces::ICloseable* tem = dynamic_cast<interfaces::ICloseable*>(any_cast<BaseComposite*>(topLevelWindow));
			
			return tem && tem->getOnClose()();
		}
	}
}
