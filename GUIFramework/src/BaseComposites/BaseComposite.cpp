#include "pch.h"
#include "BaseComposite.h"

using namespace std;

namespace gui_framework
{
	BaseComposite::BaseComposite(const wstring& className, const wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent, const string& windowFunctionName) :
		BaseComponent
		(
			className,
			windowName,
			settings,
			parent,
			windowFunctionName
		)
	{

	}

	void BaseComposite::addChild(BaseComponent* child)
	{
		children.push_back(unique_ptr<BaseComponent>(child));
	}

	void BaseComposite::removeChild(BaseComponent* child)
	{
		for (auto it = children.begin(); it != children.end(); it++)
		{
			if (it->get() == child)
			{
				children.erase(it);

				break;
			}
		}
	}

	bool BaseComposite::isComposite() const
	{
		return true;
	}

	LRESULT BaseComposite::windowMessagesHandle(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		for (const auto& i : children)
		{
			LRESULT result = i->windowMessagesHandle(handle, msg, wparam, lparam, isUsed);

			if (isUsed)
			{
				return result;
			}
		}

		isUsed = false;

		return -1;
	}
}
