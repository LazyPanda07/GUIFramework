#include "pch.h"
#include "BaseComposite.h"

using namespace std;

namespace gui_framework
{
	void getNextComponent(BaseComponent*& currentComponent, stack<BaseComposite*>& parents, stack<size_t>& indices);

	void getPreviousComponent(BaseComponent*& currentComponent, stack<BaseComposite*>& parents, stack<size_t>& indices);

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	using iterator = BaseComposite::iterator;
	using const_iterator = BaseComposite::const_iterator;

	iterator::iterator(BaseComponent* component) :
		currentComponent(component)
	{

	}

	BaseComponent* iterator::operator * () noexcept
	{
		return currentComponent;
	}

	const BaseComponent* iterator::operator * () const noexcept
	{
		return currentComponent;
	}

	BaseComponent* iterator::operator -> () noexcept
	{
		return currentComponent;
	}

	const BaseComponent* iterator::operator -> () const noexcept
	{
		return currentComponent;
	}

	interfaces::IBaseConstIterator<BaseComponent>& iterator::operator ++ () noexcept
	{
		getNextComponent(currentComponent, parents, indices);

		return *this;
	}

	unique_ptr<interfaces::IBaseConstIterator<BaseComponent>> iterator::operator ++ (int) noexcept
	{
		unique_ptr<iterator> tem(make_unique<iterator>(*this));

		getNextComponent(currentComponent, parents, indices);

		return tem;
	}

	interfaces::IBaseConstIterator<BaseComponent>& iterator::operator -- () noexcept
	{
		getPreviousComponent(currentComponent, parents, indices);

		return *this;
	}

	unique_ptr<interfaces::IBaseConstIterator<BaseComponent>> iterator::operator -- (int) noexcept
	{
		unique_ptr<iterator> tem(make_unique<iterator>(*this));

		getPreviousComponent(currentComponent, parents, indices);

		return tem;
	}

	bool iterator::operator == (const IBaseConstIterator<BaseComponent>& iterator) const noexcept
	{
		return currentComponent == *iterator;
	}

	bool iterator::operator != (const IBaseConstIterator<BaseComponent>& iterator) const noexcept
	{
		return currentComponent != *iterator;
	}

	const_iterator::const_iterator(BaseComponent* component) :
		currentComponent(component)
	{

	}

	const BaseComponent* const_iterator::operator * () const noexcept
	{
		return currentComponent;
	}

	const BaseComponent* const_iterator::operator -> () const noexcept
	{
		return currentComponent;
	}

	interfaces::IBaseConstIterator<BaseComponent>& const_iterator::operator ++ () noexcept
	{
		getNextComponent(currentComponent, parents, indices);

		return *this;
	}

	unique_ptr<interfaces::IBaseConstIterator<BaseComponent>> const_iterator::operator ++ (int) noexcept
	{
		unique_ptr<const_iterator> tem(make_unique<const_iterator>(*this));

		getNextComponent(currentComponent, parents, indices);

		return tem;
	}

	interfaces::IBaseConstIterator<BaseComponent>& const_iterator::operator -- () noexcept
	{
		getPreviousComponent(currentComponent, parents, indices);

		return *this;
	}

	unique_ptr<interfaces::IBaseConstIterator<BaseComponent>> const_iterator::operator -- (int) noexcept
	{
		unique_ptr<const_iterator> tem(make_unique<const_iterator>(*this));

		getPreviousComponent(currentComponent, parents, indices);

		return tem;
	}

	bool const_iterator::operator == (const IBaseConstIterator<BaseComponent>& iterator) const noexcept
	{
		return currentComponent == *iterator;
	}

	bool const_iterator::operator != (const IBaseConstIterator<BaseComponent>& iterator) const noexcept
	{
		return currentComponent != *iterator;
	}

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

	bool BaseComposite::isComposite() const
	{
		return true;
	}

	unique_ptr<interfaces::IBaseIterator<BaseComponent>> BaseComposite::begin() noexcept
	{
		return make_unique<iterator>(this);
	}

	unique_ptr<interfaces::IBaseConstIterator<BaseComponent>> BaseComposite::cbegin() const noexcept
	{
		return make_unique<const_iterator>(static_cast<BaseComponent*>(const_cast<BaseComposite*>(this)));
	}

	unique_ptr<interfaces::IBaseIterator<BaseComponent>> BaseComposite::end() noexcept
	{
		return make_unique<iterator>(nullptr);
	}

	unique_ptr<interfaces::IBaseConstIterator<BaseComponent>> BaseComposite::cend() const noexcept
	{
		return make_unique<const_iterator>(nullptr);
	}

	BaseComposite::~BaseComposite()
	{
		vector<BaseComponent*> components;

		for_each(children.begin(), children.end(), [&components](const unique_ptr<BaseComponent>& component) { components.push_back(component.get()); });

		for_each(components.begin(), components.end(), [this](BaseComponent* component) { this->removeChild(component); });
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	void getNextComponent(BaseComponent*& currentComponent, stack<BaseComposite*>& parents, stack<size_t>& indices)
	{
		BaseComposite* composite = dynamic_cast<BaseComposite*>(currentComponent);

		if (composite)
		{
			const vector<unique_ptr<BaseComponent>>& components = composite->getChildren();

			if (components.size())
			{
				indices.push(1);

				parents.push(composite);

				currentComponent = components.front().get();
			}
			else if (parents.size())
			{
				BaseComposite* composite = parents.top();
				size_t nextIndex = indices.top();
				const vector<unique_ptr<BaseComponent>>& components = composite->getChildren();

				parents.pop();
				indices.pop();

				if (nextIndex < components.size())
				{
					parents.push(composite);
					indices.push(nextIndex + 1);

					currentComponent = components[nextIndex].get();
				}
				else
				{
					getNextComponent(currentComponent, parents, indices);
				}
			}
		}
		else
		{
			if (parents.size())
			{
				BaseComposite* composite = parents.top();
				size_t nextIndex = indices.top();
				const vector<unique_ptr<BaseComponent>>& components = composite->getChildren();

				parents.pop();
				indices.pop();

				if (nextIndex < components.size())
				{
					parents.push(composite);
					indices.push(nextIndex + 1);

					currentComponent = components[nextIndex].get();
				}
				else
				{
					getNextComponent(currentComponent, parents, indices);
				}
			}
		}
	}

	void getPreviousComponent(BaseComponent*& currentComponent, stack<BaseComposite*>& parents, stack<size_t>& indices)
	{
		BaseComposite* composite = nullptr;

		if (currentComponent)
		{
			composite = dynamic_cast<BaseComposite*>(currentComponent);
		}
		else
		{
			const vector<unique_ptr<BaseComponent>>& components = parents.top()->getChildren();

			if (components.size())
			{
				currentComponent = components.back().get();
			}
		}

		if (composite)
		{
			const vector<unique_ptr<BaseComponent>>& components = composite->getChildren();

			if (components.size())
			{
				indices.push(components.size() - 1);

				parents.push(composite);

				currentComponent = components.back().get();
			}
			else if (parents.size())
			{
				BaseComposite* composite = parents.top();
				int64_t previousIndex = indices.top();
				const vector<unique_ptr<BaseComponent>>& components = composite->getChildren();

				parents.pop();
				indices.pop();

				if (previousIndex > -1)
				{
					parents.push(composite);
					indices.push(previousIndex - 1);

					currentComponent = components[previousIndex].get();
				}
				else
				{
					getNextComponent(currentComponent, parents, indices);
				}
			}
		}
		else
		{
			if (parents.size())
			{
				BaseComposite* composite = parents.top();
				int64_t previousIndex = indices.top();
				const vector<unique_ptr<BaseComponent>>& components = composite->getChildren();

				parents.pop();
				indices.pop();

				if (previousIndex > -1)
				{
					parents.push(composite);
					indices.push(previousIndex - 1);

					currentComponent = components[previousIndex].get();
				}
				else
				{
					getNextComponent(currentComponent, parents, indices);
				}
			}
		}
	}
}
