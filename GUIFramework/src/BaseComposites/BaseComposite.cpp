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
				it->reset();

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

	BaseComponent* BaseComposite::findChild(HWND handle) const
	{
		BaseComponent* result = nullptr;
	
		for (const auto& i : children)
		{
			if (i->getHandle() == handle)
			{
				result = i.get();
	
				break;
			}
			else if (i->isComposite())
			{
				result = static_cast<BaseComposite*>(i.get())->findChild(handle);
	
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

	const vector<unique_ptr<BaseComponent>>& BaseComposite::getChildren() const
	{
		return children;
	}

	LRESULT BaseComposite::compositeWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		if (message >= WM_CTLCOLOREDIT && message <= WM_CTLCOLORSTATIC)
		{
			BaseComponent* component = this->findChild(reinterpret_cast<HWND>(lparam));

			if (component)
			{
				isUsed = true;

				SetBkColor(reinterpret_cast<HDC>(wparam), component->getBackgroundColor());

				return reinterpret_cast<LRESULT>(CreateSolidBrush(component->getBackgroundColor()));
			}
		}

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

		result = BaseComponent::windowMessagesHandle(handle, message, wparam, lparam, isUsed);

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

	bool BaseComposite::isComposite() const
	{
		return true;
	}

	iterators::forward_iterator BaseComposite::begin() noexcept
	{
		return iterators::forward_iterator(this);
	}

	iterators::const_forward_iterator BaseComposite::cbegin() const noexcept
	{
		return iterators::const_forward_iterator(static_cast<BaseComponent*>(const_cast<BaseComposite*>(this)));
	}

	iterators::forward_iterator BaseComposite::end() noexcept
	{
		return iterators::forward_iterator(nullptr);
	}

	iterators::const_forward_iterator BaseComposite::cend() const noexcept
	{
		return iterators::const_forward_iterator(nullptr);
	}

	void BaseComposite::setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		BaseComponent::setBackgroundColor(red, green, blue);

		SetWindowLongPtrW(handle, GCLP_HBRBACKGROUND, reinterpret_cast<LONG_PTR>(CreateSolidBrush(backgroundColor)));

		InvalidateRect(handle, nullptr, true);
	}

	BaseComposite::~BaseComposite()
	{
		vector<BaseComponent*> components;

		for_each(children.begin(), children.end(), [&components](const unique_ptr<BaseComponent>& component) { components.push_back(component.get()); });

		for_each(components.begin(), components.end(), [this](BaseComponent* component) { this->removeChild(component); });
	}
}
