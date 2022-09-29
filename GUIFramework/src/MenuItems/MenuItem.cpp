#include "core.h"
#include "MenuItem.h"

#include "GUIFramework.h"

#include "Exceptions/CantFindFunctionFromModuleException.h"

using namespace std;

namespace gui_framework
{
	MenuItem::MenuItem(const wstring& text, const function<void()>& onClick) :
		BaseMenuItem(text),
		onClick(onClick)
	{

	}

	MenuItem::MenuItem(const wstring& text, const string& functionName, const string& moduleName) :
		BaseMenuItem(text),
		functionName(functionName),
		moduleName(moduleName)
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

	void MenuItem::processMessage()
	{
		onClick();
	}

	json::JSONBuilder MenuItem::getStructure() const
	{
		using json::utility::jsonObject;

		if (functionName.empty())
		{
			return BaseMenuItem::getStructure();
		}

		json::JSONBuilder builder = BaseMenuItem::getStructure();
		
		builder.
			append("functionName", functionName).
			append("moduleName", moduleName);

		return builder;
	}
}
