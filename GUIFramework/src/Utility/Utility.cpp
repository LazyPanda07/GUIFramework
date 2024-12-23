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
		void unregisterClass(wstring_view className)
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

		string to_string(wstring_view stringToConvert, uint32_t codepage)
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

		HMODULE getCurrentModule()
		{
			return GetModuleHandleW(nullptr);
		}

		string getStringFromRawPath(const filesystem::path& pathFromRawString)
		{
			ostringstream fixRawString;
			string fixedPath;

			fixRawString << pathFromRawString;

			fixedPath = fixRawString.str();

			erase(fixedPath, '\"');

			return fixedPath;
		}

		void loadFunctionFromModule(function<void()>& onClick, const string& functionName, const string& moduleName)
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

		void loadEventCallbackFromModule(function<void(const wstring&)>& eventCallback, const string& functionName, const string& moduleName)
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

		int getCenterX(int width)
		{
			return (GetSystemMetrics(SM_CXSCREEN) - GetSystemMetrics(SM_CXBORDER) - width) / 2;
		}

		int getCenterY(int height)
		{
			return (GetSystemMetrics(SM_CYSCREEN) - GetSystemMetrics(SM_CYBORDER) - height) / 2;
		}

		string getGUIFrameworkVersion()
		{
			return "1.0.2";
		}
	}

	namespace __utility
	{
		void throwNotImplementedException(string_view methodName, string_view className)
		{
			try
			{
				if (GUIFramework::get().getJSONSettings().getBool(json_settings::usingNotImplementedExceptions))
				{
					throw exceptions::NotImplemented(methodName, className, __FILE__, __LINE__);
				}
			}
			catch (const json::exceptions::CantFindValueException&)
			{

			}
		}

		string extendedException(const string& exceptionMessage, string_view fileName, string_view methodName, int line)
		{
			try
			{
				if (GUIFramework::get().getJSONSettings().getBool(json_settings::usingExtendedExceptions))
				{
					return format(R"({} in file "{}" in "{}" method on {} line)"sv, exceptionMessage, fileName.substr(fileName.rfind('\\') + 1), methodName, line);
				}
			}
			catch (const json::exceptions::CantFindValueException&)
			{
				
			}

			return exceptionMessage;
		}

		bool useOnClose(any topLevelWindow)
		{
			interfaces::ICloseable* tem = dynamic_cast<interfaces::ICloseable*>(any_cast<BaseComposite*>(topLevelWindow));
			
			return tem && tem->getOnClose()();
		}
	}
}
