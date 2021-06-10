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

	void BaseComposite::removeComponents(const wstring& componentName)
	{
		erase_if(children, [&componentName](const unique_ptr<BaseComponent>& child) { return child->getWindowName() == componentName; });
	}

	BaseComponent* BaseComposite::findChild(const wstring& windowName) const
	{
		BaseComponent* result = nullptr;

		for (const auto& i : children)
		{
			if (i->getWindowName() == windowName)
			{
				result = i.get();

				break;
			}
			else if (i->isComposite())
			{
				result = static_cast<BaseComposite*>(i.get())->findChild(windowName);

				if (result)
				{
					break;
				}
			}
		}

		return result;
	}

	vector<BaseComponent*> BaseComposite::findChildren(const wstring& windowName) const
	{
		vector<BaseComponent*> result;

		for (const auto& i : children)
		{
			if (i->getWindowName() == windowName)
			{
				result.push_back(i.get());
			}
			else if (i->isComposite())
			{
				vector<BaseComponent*> subChildren = static_cast<BaseComposite*>(i.get())->findChildren(windowName);

				copy(subChildren.begin(), subChildren.end(), back_inserter(result));
			}
		}

		return result;
	}

	bool BaseComposite::isComposite() const
	{
		return true;
	}

	LRESULT BaseComposite::compositeWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		isUsed = false;

		return -1;
	}

	LRESULT BaseComposite::windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		LRESULT result = this->compositeWindowMessagesHandle(handle, message, wparam, lparam, isUsed);

		if (isUsed)
		{
			return result;
		}

		for (const auto& i : children)
		{
			if (!i)
			{
				continue;
			}

			result = i->windowMessagesHandle(handle, message, wparam, lparam, isUsed);

			if (isUsed)
			{
				return result;
			}
		}

		isUsed = false;

		return -1;
	}

	const vector<unique_ptr<BaseComponent>>& BaseComposite::getChildren() const
	{
		return children;
	}
}
