#include "ICloseable.h"

#include "CompositesHeader.h"
#include "Exceptions/CantFindFunctionFromModuleException.h"

using namespace std;

namespace gui_framework
{
	namespace interfaces
	{
		ICloseable::ICloseable(HWND closeableHandle) :
			closeableHandle(closeableHandle),
			onClose([]() { return true; })
		{

		}

		bool ICloseable::close(int exitCode)
		{
			dynamic_cast<BaseComposite*>(this)->setExitCode(exitCode);

			return DestroyWindow(closeableHandle);
		}

		void ICloseable::setOnClose(const function<bool()>& onClose)
		{
			this->onClose = onClose;

			onCloseFunctionName.clear();
			onCloseFunctionModuleName.clear();
		}

		void ICloseable::setOnClose(const string& onCloseFunctionName, const string& onCloseFunctionModuleName)
		{
			GUIFramework& instance = GUIFramework::get();
			const HMODULE& module = instance.getModules().at(onCloseFunctionModuleName);

			onCloseSignature tem = reinterpret_cast<onCloseSignature>(GetProcAddress(module, onCloseFunctionName.data()));

			if (!tem)
			{
				throw exceptions::CantFindFunctionFromModuleException(onCloseFunctionName, onCloseFunctionModuleName, __FILE__, __FUNCTION__, __LINE__);
			}

			onClose = tem;

			this->onCloseFunctionName = onCloseFunctionName;
			this->onCloseFunctionModuleName = onCloseFunctionModuleName;
		}

		const function<bool()>& ICloseable::getOnClose() const
		{
			return onClose;
		}
	}
}
