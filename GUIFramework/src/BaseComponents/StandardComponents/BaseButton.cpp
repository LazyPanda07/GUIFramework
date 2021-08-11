#include "pch.h"
#include "BaseButton.h"

#include "Exceptions/GetLastErrorException.h"
#include "Exceptions/NotImplemented.h"
#include "Exceptions/CantFindFunctionFromModuleException.h"

using namespace std;

namespace gui_framework
{
	LRESULT BaseButton::windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		if (message == WM_COMMAND && id == LOWORD(wparam))
		{
			isUsed = true;

			if (onClick)
			{
				onClick();
			}

			return 0;
		}

		isUsed = false;

		return -1;
	}

	BaseButton::BaseButton(const wstring& buttonName, const wstring& buttonText, const utility::ComponentSettings& settings, const styles::ButtonStyles& styles, BaseComponent* parent, const function<void()>& onClick) :
		BaseComponent
		(
			wstring(standard_classes::button),
			buttonName,
			settings,
			styles,
			parent
		),
		ITextOperations(handle),
		onClick(onClick)
	{
		this->setText(buttonText);
	}

	BaseButton::BaseButton(const wstring& buttonName, const wstring& buttonText, const utility::ComponentSettings& settings, const styles::ButtonStyles& styles, BaseComponent* parent, const string& functionName, const string& moduleName) :
		BaseComponent
		(
			wstring(standard_classes::button),
			buttonName,
			settings,
			styles,
			parent
		),
		ITextOperations(handle)
	{
		this->setText(buttonText);

		this->setOnClick(functionName, moduleName);
	}

	void BaseButton::setOnClick(const function<void()>& onClick)
	{
		this->onClick = onClick;

		functionName.clear();
		moduleName.clear();
	}

	void BaseButton::setOnClick(const string& functionName, const string& moduleName)
	{
		GUIFramework& instance = GUIFramework::get();
		const HMODULE& module = instance.getModules().at(moduleName);

		onClickSignature tem = reinterpret_cast<onClickSignature>(GetProcAddress(module, functionName.data()));

		if (!tem)
		{
			throw exceptions::CantFindFunctionFromModuleException(functionName, moduleName);
		}

		onClick = tem;

		this->functionName = functionName;
		this->moduleName = moduleName;
	}

	const function<void()>& BaseButton::getOnClick() const
	{
		return onClick;
	}

	const string& BaseButton::getFunctionName() const
	{
		return functionName;
	}

	const string& BaseButton::getModuleName() const
	{
		return moduleName;
	}

	void BaseButton::setTextColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		throw exceptions::NotImplemented(__FUNCTION__, "BaseButton");
	}

	json::JSONBuilder BaseButton::getStructure() const
	{
		using json::utility::jsonObject;
		using json::utility::objectSmartPointer;

		if (functionName.empty())
		{
			return BaseComponent::getStructure();
		}

		json::JSONBuilder builder = BaseComponent::getStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		current->data.push_back({ "functionName"s, functionName });

		current->data.push_back({ "moduleName"s, moduleName });

		current->data.push_back({ "pathToModule"s, GUIFramework::get().getModulesPaths().at(moduleName) });

		return builder;
	}
}
