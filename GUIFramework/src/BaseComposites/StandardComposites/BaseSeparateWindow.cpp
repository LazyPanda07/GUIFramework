#include "headers.h"
#include "BaseSeparateWindow.h"

#include "Styles/Composites/SeparateWindowStyles.h"
#include "Exceptions/CantFindFunctionFromModuleException.h"

using namespace std;

namespace gui_framework
{
	BaseSeparateWindow::BaseSeparateWindow(const wstring& className, const wstring& titleName, const utility::ComponentSettings& settings, const string& windowFunctionName, bool maximize, bool minimize, const string& moduleName, uint16_t smallIconResource, uint16_t largeIconResource) :
		BaseWindow
		(
			className,
			titleName,
			settings,
			styles::SeparateWindowStyles(maximize, minimize),
			nullptr,
			windowFunctionName,
			moduleName,
			smallIconResource,
			largeIconResource
		),
		onClose([]() { return true; })
	{

	}

	void BaseSeparateWindow::setOnClose(const function<bool()>& onClose)
	{
		this->onClose = onClose;

		onCloseFunctionName.clear();
		onCloseFunctionModuleName.clear();
	}

	void BaseSeparateWindow::setOnClose(const string& onCloseFunctionName, const string& onCloseFunctionModuleName)
	{
		GUIFramework& instance = GUIFramework::get();
		const HMODULE& module = instance.getModules().at(onCloseFunctionModuleName);

		onCloseSignature tem = reinterpret_cast<onCloseSignature>(GetProcAddress(module, onCloseFunctionName.data()));

		if (!tem)
		{
			throw exceptions::CantFindFunctionFromModuleException(onCloseFunctionName, onCloseFunctionModuleName);
		}

		onClose = tem;

		this->onCloseFunctionName = onCloseFunctionName;
		this->onCloseFunctionModuleName = onCloseFunctionModuleName;
	}

	const function<bool()>& BaseSeparateWindow::getOnClose() const
	{
		return onClose;
	}

	json::JSONBuilder BaseSeparateWindow::getStructure() const
	{
		using json::utility::jsonObject;
		using json::utility::objectSmartPointer;

		json::JSONBuilder builder = BaseWindow::getStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		if (onCloseFunctionName.size())
		{
			current->data.push_back({ "onCloseFunctionName"s, onCloseFunctionName });
			current->data.push_back({ "onCloseFunctionModuleName"s, onCloseFunctionModuleName });
		}

		return builder;
	}
}

