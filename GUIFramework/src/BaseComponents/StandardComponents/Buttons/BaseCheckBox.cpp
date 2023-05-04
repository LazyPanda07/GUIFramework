#include "BaseCheckBox.h"

#include "Styles/Components/Buttons/CheckBoxStyles.h"
#include "GUIFramework.h"

#include "Exceptions/CantFindFunctionFromModuleException.h"

using namespace std;

namespace gui_framework
{
	LRESULT BaseCheckBox::windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		if (message == WM_COMMAND && id == LOWORD(wparam))
		{
			isUsed = true;

			LRESULT state = SendMessageW(this->handle, BM_GETCHECK, NULL, NULL);

			SendMessageW(this->handle, BM_SETCHECK, !state, NULL);

			if (onClear && state == BST_CHECKED)
			{
				onClear();

				return 0;
			}
			else if (onCheck && state == BST_UNCHECKED)
			{
				onCheck();

				return 0;
			}
			else if (onClick)
			{
				onClick();

				return 0;
			}
		}

		isUsed = false;

		return -1;
	}

	BaseCheckBox::BaseCheckBox(const wstring& checkBoxName, const wstring& checkBoxText, const utility::ComponentSettings& settings, BaseComposite* parent, const function<void()>& onCheck, const function<void()>& onClear, const function<void()>& onClick) :
		BaseButton
		(
			checkBoxName,
			checkBoxText,
			settings,
			styles::CheckBoxStyles(),
			parent,
			onClick
		),
		onCheck(onCheck),
		onClear(onClear)
	{

	}

	void BaseCheckBox::setOnCheck(const function<void()>& onCheck)
	{
		this->onCheck = onCheck;

		onCheckFunctionName.clear();
		onCheckModuleName.clear();
	}

	void BaseCheckBox::setOnCheck(const string& functionName, const string& moduleName)
	{
		GUIFramework& instance = GUIFramework::get();
		const HMODULE& module = instance.getModules().at(moduleName);

		onClickSignature tem = reinterpret_cast<onClickSignature>(GetProcAddress(module, functionName.data()));

		if (!tem)
		{
			throw exceptions::CantFindFunctionFromModuleException(functionName, moduleName, __FILE__, __FUNCTION__, __LINE__);
		}

		onCheck = tem;

		this->onCheckFunctionName = functionName;
		this->onCheckModuleName = moduleName;
	}

	void BaseCheckBox::setOnClear(const function<void()>& onClear)
	{
		this->onClear = onClear;

		onClearFunctionName.clear();
		onClearModuleName.clear();
	}

	void BaseCheckBox::setOnClear(const string& functionName, const string& moduleName)
	{
		GUIFramework& instance = GUIFramework::get();
		const HMODULE& module = instance.getModules().at(moduleName);

		onClickSignature tem = reinterpret_cast<onClickSignature>(GetProcAddress(module, functionName.data()));

		if (!tem)
		{
			throw exceptions::CantFindFunctionFromModuleException(functionName, moduleName, __FILE__, __FUNCTION__, __LINE__);
		}

		onClear = tem;

		this->onClearFunctionName = functionName;
		this->onClearModuleName = moduleName;
	}

	const function<void()>& BaseCheckBox::getOnCheck() const
	{
		return onCheck;
	}

	const function<void()>& BaseCheckBox::getOnClear() const
	{
		return onClear;
	}

	json::JSONBuilder BaseCheckBox::getStructure() const
	{
		using json::utility::jsonObject;

		if (onCheckFunctionName.empty() && onClearFunctionName.empty())
		{
			return BaseButton::getStructure();
		}

		json::JSONBuilder builder = BaseButton::getStructure();
		jsonObject& current = get<jsonObject>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);
		const auto& modulesPaths = GUIFramework::get().getModulesPaths();

		if (onCheckFunctionName.size())
		{
			current.data.push_back({ "checkFunctionName"s, onCheckFunctionName });

			current.data.push_back({ "checkModuleName"s, modulesPaths.at(onCheckModuleName) });
		}

		if (onClearFunctionName.size())
		{
			current.data.push_back({ "clearFunctionName"s, onClearFunctionName });

			current.data.push_back({ "clearModuleName"s, modulesPaths.at(onClearModuleName) });
		}

		return builder;
	}
}
