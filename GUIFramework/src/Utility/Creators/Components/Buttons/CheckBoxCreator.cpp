#include "CheckBoxCreator.h"

#include "Components/Buttons/CheckBox.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* CheckBoxCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComposite* parent)
		{
			auto [text, onCheck, onClear, onClick, onCheckFunctionName, onCheckFunctionModule, onClearFunctionName, onClearFunctionModule, onClickFunctionName, onClickFunctionModule] =
				any_cast<tuple<wstring, function<void()>, function<void()>, function<void()>, string, string, string, string, string, string>>(additionalData);

			CheckBox* result = new CheckBox(windowName, text, settings, parent, nullptr, nullptr, nullptr);

			if (onCheck)
			{
				result->setOnCheck(onCheck);
			}
			else if (onCheckFunctionName.size())
			{
				result->setOnCheck(onCheckFunctionName, onCheckFunctionModule);
			}

			if (onClear)
			{
				result->setOnClear(onClear);
			}
			else if (onClearFunctionName.size())
			{
				result->setOnCheck(onClearFunctionName, onClearFunctionModule);
			}

			if (onClick)
			{
				result->setOnClick(onClick);
			}
			else if (onClickFunctionName.size())
			{
				result->setOnClick(onClickFunctionName, onClickFunctionModule);
			}

			return result;
		}
	}
}
