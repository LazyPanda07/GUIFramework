#include "pch.h"
#include "BaseComposite.h"

#include "Interfaces/Components/IResizableComponent.h"

#include "Exceptions/FileDoesNotExist.h"

using namespace std;

namespace gui_framework
{
	LRESULT BaseComposite::preWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		isUsed = false;

		if (message == WM_SIZE)
		{
			interfaces::IResizableComponent* resizableComposite = dynamic_cast<interfaces::IResizableComponent*>(this);

			if (resizableComposite && resizableComposite->getBlockResize())
			{
				isUsed = true;

				uint16_t width = LOWORD(lparam);
				uint16_t height = HIWORD(lparam);

				for (const auto& i : children)
				{
					interfaces::IResizableComponent* resizable = dynamic_cast<interfaces::IResizableComponent*>(i.get());

					if (resizable)
					{
						resizable->resize(width, height);
					}
				}

				return 0;
			}
		}

		return -1;
	}

	vector<pair<string, json::utility::objectSmartPointer<json::utility::jsonObject>>> BaseComposite::getChildrenStructure() const
	{
		vector<json::JSONBuilder> childrenStructure;
		vector<pair<string, json::utility::objectSmartPointer<json::utility::jsonObject>>> data;

		childrenStructure.reserve(children.size());

		for_each(children.begin(), children.end(), [&childrenStructure](const unique_ptr<BaseComponent>& child) { childrenStructure.push_back(child->getStructure()); });

		for (size_t i = 0; i < children.size(); i++)
		{
			string childWindowName = utility::to_string(children[i]->getWindowName(), children[i]->getCodepage());

			auto& childStructure = get<json::utility::objectSmartPointer<json::utility::jsonObject>>(childrenStructure[i][childWindowName]);

			data.push_back({ move(childWindowName), move(childStructure) });
		}

		return data;
	}

	json::JSONBuilder BaseComposite::getStructure() const
	{
		using json::utility::jsonObject;
		using json::utility::objectSmartPointer;

		json::JSONBuilder builder = BaseComponent::getStructure();
		uint32_t codepage = ISerializable::getCodepage();
		vector<pair<string, objectSmartPointer<jsonObject>>> data = this->getChildrenStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, codepage)]);

		if (pathToSmallIcon.size())
		{
			current->data.push_back({ "pathToSmallIcon"s, pathToSmallIcon });
		}

		if (pathToLargeIcon.size())
		{
			current->data.push_back({ "pathToLargeIcon"s, pathToLargeIcon });
		}

		if (data.size())
		{
			vector<objectSmartPointer<jsonObject>>& childrenStructures = get<vector<objectSmartPointer<jsonObject>>>(current->data.emplace_back(make_pair("children"s, vector<objectSmartPointer<jsonObject>>())).second);

			for (auto& i : data)
			{
				objectSmartPointer<jsonObject> topLevel = json::utility::make_object<jsonObject>();
				objectSmartPointer<jsonObject> tem = json::utility::make_object<jsonObject>();

				tem->data.push_back(move(i));

				topLevel->data.push_back({ ""s, move(tem) });

				childrenStructures.push_back(move(topLevel));
			}
		}

		return builder;
	}

	BaseComposite::BaseComposite(const wstring& className, const wstring& windowName, const utility::ComponentSettings& settings, const interfaces::IStyles& styles, BaseComponent* parent, const string& windowFunctionName) :
		BaseComponent
		(
			className,
			windowName,
			settings,
			styles,
			parent,
			windowFunctionName
		),
		largeIcon(nullptr),
		smallIcon(nullptr)
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

				SetTextColor(reinterpret_cast<HDC>(wparam), component->getTextColor());

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

	void BaseComposite::setLargeIcon(const filesystem::path& pathToLargeIcon)
	{
		if (!filesystem::exists(pathToLargeIcon))
		{
			throw exceptions::FileDoesNotExist(pathToLargeIcon);
		}

		this->pathToLargeIcon = pathToLargeIcon.string();

		if (largeIcon)
		{
			DestroyIcon(largeIcon);

			largeIcon = nullptr;
		}

		largeIcon = static_cast<HICON>(LoadImageW(nullptr, pathToLargeIcon.wstring().data(), IMAGE_ICON, standard_sizes::largeIconWidth, standard_sizes::largeIconHeight, LR_LOADFROMFILE));

		SendMessageW(handle, WM_SETICON, ICON_BIG, reinterpret_cast<LPARAM>(largeIcon));
	}

	void BaseComposite::setSmallIcon(const filesystem::path& pathToSmallIcon)
	{
		if (!filesystem::exists(pathToSmallIcon))
		{
			throw exceptions::FileDoesNotExist(pathToSmallIcon);
		}

		this->pathToSmallIcon = pathToSmallIcon.string();

		if (smallIcon)
		{
			DestroyIcon(smallIcon);

			smallIcon = nullptr;
		}

		smallIcon = static_cast<HICON>(LoadImageW(nullptr, pathToSmallIcon.wstring().data(), IMAGE_ICON, standard_sizes::smallIconWidth, standard_sizes::smallIconHeight, LR_LOADFROMFILE));

		SendMessageW(handle, WM_SETICON, ICON_SMALL, reinterpret_cast<LPARAM>(smallIcon));
	}

	iterators::composite_forward_iterator BaseComposite::begin() noexcept
	{
		return iterators::composite_forward_iterator(this);
	}

	iterators::composite_const_forward_iterator BaseComposite::cbegin() const noexcept
	{
		return iterators::composite_const_forward_iterator(static_cast<BaseComponent*>(const_cast<BaseComposite*>(this)));
	}

	iterators::composite_forward_iterator BaseComposite::end() noexcept
	{
		return iterators::composite_forward_iterator(nullptr);
	}

	iterators::composite_const_forward_iterator BaseComposite::cend() const noexcept
	{
		return iterators::composite_const_forward_iterator(nullptr);
	}

	void BaseComposite::setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		BaseComponent::setBackgroundColor(red, green, blue);

		SetClassLongPtrW(handle, GCLP_HBRBACKGROUND, reinterpret_cast<LONG_PTR>(CreateSolidBrush(backgroundColor)));

		InvalidateRect(handle, nullptr, true);
	}

	BaseComposite::~BaseComposite()
	{
		vector<BaseComponent*> components;

		for_each(children.begin(), children.end(), [&components](const unique_ptr<BaseComponent>& component) { components.push_back(component.get()); });

		for_each(components.begin(), components.end(), [this](BaseComponent* component) { this->removeChild(component); });

		DestroyIcon(largeIcon);
		DestroyIcon(smallIcon);
	}
}
