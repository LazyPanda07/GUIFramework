#include "core.h"
#include "BaseTabControl.h"

#include "Styles/DefaultStyles.h"
#include "GUIFramework.h"

#include "Exceptions/FileDoesNotExist.h"
#include "Exceptions/NotImplemented.h"
#include "Exceptions/CantFindFunctionFromModuleException.h"

#pragma warning(disable: 26454)

using namespace std;

namespace gui_framework
{
	using tabData = BaseTabControl::tabData;

	tabData::tabData(const wstring& text, const filesystem::path& pathToImage, const function<void()>& callback) :
		text(text),
		pathToImage(pathToImage),
		callback(callback)
	{

	}

	tabData::tabData(const wstring& text, const filesystem::path& pathToImage, const string& functionName, const string& moduleName) :
		text(text),
		pathToImage(pathToImage),
		functionName(functionName),
		moduleName(moduleName)
	{
		onClickSignature tem = reinterpret_cast<onClickSignature>(GetProcAddress(GUIFramework::get().getModules().at(moduleName), functionName.data()));

		if (!tem)
		{
			throw exceptions::CantFindFunctionFromModuleException(functionName, moduleName, __FILE__, __FUNCTION__, __LINE__);
		}

		callback = tem;
	}

	LRESULT BaseTabControl::windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		if (message == WM_NOTIFY)
		{
			NMHDR* notification = reinterpret_cast<NMHDR*>(lparam);

			if (notification->code == TCN_SELCHANGE)
			{
				isUsed = true;

				LRESULT currentTab = this->getSelectedTab();

				if (currentTab != -1)
				{
					callbacks[currentTab]();
				}

				return 0;
			}
		}

		isUsed = false;

		return -1;
	}

	BaseTabControl::BaseTabControl(const wstring& tabControlName, const utility::ComponentSettings& settings, uint16_t imagesWidth, uint16_t imagesHeight, BaseComposite* parent) :
		BaseComponent
		(
			standard_classes::tabControl,
			tabControlName,
			settings,
			styles::DefaultStyles(),
			parent
		),
		images(imagesWidth, imagesHeight)
	{
		SendMessageW(handle, TCM_SETIMAGELIST, NULL, reinterpret_cast<LPARAM>(images.getImageList()));
	}

	LRESULT BaseTabControl::appendText(const wstring& text, const function<void()>& onClick)
	{
		return this->insertText(this->size(), text, onClick);
	}

	LRESULT BaseTabControl::appendText(const wstring& text, const string& functionName, const string& moduleName)
	{
		return this->insertText(this->size(), text, functionName, moduleName);
	}

	LRESULT BaseTabControl::insertText(size_t index, const wstring& text, const function<void()>& onClick)
	{
		TCITEMW item = {};

		item.mask = TCIF_TEXT;
		item.pszText = const_cast<wchar_t*>(text.data());
		item.cchTextMax = static_cast<int>(text.size());

		LRESULT result = SendMessageW(handle, TCM_INSERTITEM, index, reinterpret_cast<LPARAM>(&item));

		if (result != -1)
		{
			auto it = callbacks.insert(callbacks.begin() + index, onClick);

			tabs.emplace(tabs.begin() + index, text, filesystem::path(), *it);
		}

		return result;
	}

	LRESULT BaseTabControl::insertText(size_t index, const wstring& text, const string& functionName, const string& moduleName)
	{
		TCITEMW item = {};

		item.mask = TCIF_TEXT;
		item.pszText = const_cast<wchar_t*>(text.data());
		item.cchTextMax = static_cast<int>(text.size());

		LRESULT result = SendMessageW(handle, TCM_INSERTITEM, index, reinterpret_cast<LPARAM>(&item));

		if (result != -1)
		{
			onClickSignature tem = reinterpret_cast<onClickSignature>(GetProcAddress(GUIFramework::get().getModules().at(moduleName), functionName.data()));

			if (!tem)
			{
				throw exceptions::CantFindFunctionFromModuleException(functionName, moduleName, __FILE__, __FUNCTION__, __LINE__);
			}

			callbacks.insert(callbacks.begin() + index, tem);

			tabs.emplace(tabs.begin() + index, text, filesystem::path(), functionName, moduleName);
		}

		return result;
	}

	LRESULT BaseTabControl::appendImage(const filesystem::path& pathToImage, const function<void()>& onClick)
	{
		return this->insertImage(this->size(), pathToImage, onClick);
	}

	LRESULT BaseTabControl::appendImage(const filesystem::path& pathToImage, const string& functionName, const string& moduleName)
	{
		return this->insertImage(this->size(), pathToImage, functionName, moduleName);
	}

	LRESULT BaseTabControl::insertImage(size_t index, const filesystem::path& pathToImage, const function<void()>& onClick)
	{
		if (!filesystem::exists(pathToImage))
		{
			throw exceptions::FileDoesNotExist(pathToImage, __FILE__, __FUNCTION__, __LINE__);
		}

		TCITEMW item = {};

		if (!images.contains(pathToImage))
		{
			images.addImage(pathToImage);
		}

		item.mask = TCIF_IMAGE;
		item.iImage = images[pathToImage];

		LRESULT result = SendMessageW(handle, TCM_INSERTITEM, index, reinterpret_cast<LPARAM>(&item));

		if (result != -1)
		{
			auto it = callbacks.insert(callbacks.begin() + index, onClick);

			tabs.emplace(tabs.begin() + index, wstring(), pathToImage, *it);
		}

		return result;
	}

	LRESULT BaseTabControl::insertImage(size_t index, const filesystem::path& pathToImage, const string& functionName, const string& moduleName)
	{
		if (!filesystem::exists(pathToImage))
		{
			throw exceptions::FileDoesNotExist(pathToImage, __FILE__, __FUNCTION__, __LINE__);
		}

		TCITEMW item = {};

		if (!images.contains(pathToImage))
		{
			images.addImage(pathToImage);
		}

		item.mask = TCIF_IMAGE;
		item.iImage = images[pathToImage];

		LRESULT result = SendMessageW(handle, TCM_INSERTITEM, index, reinterpret_cast<LPARAM>(&item));

		if (result != -1)
		{
			onClickSignature tem = reinterpret_cast<onClickSignature>(GetProcAddress(GUIFramework::get().getModules().at(moduleName), functionName.data()));

			if (!tem)
			{
				throw exceptions::CantFindFunctionFromModuleException(functionName, moduleName, __FILE__, __FUNCTION__, __LINE__);
			}

			callbacks.insert(callbacks.begin() + index, tem);

			tabs.emplace(tabs.begin() + index, wstring(), pathToImage, functionName, moduleName);
		}

		return result;
	}

	LRESULT BaseTabControl::appendTextAndImage(const wstring& text, const filesystem::path& pathToImage, const function<void()>& onClick)
	{
		return this->insertTextAndImage(this->size(), text, pathToImage, onClick);
	}

	LRESULT BaseTabControl::appendTextAndImage(const wstring& text, const filesystem::path& pathToImage, const string& functionName, const string& moduleName)
	{
		return this->insertTextAndImage(this->size(), text, pathToImage, functionName, moduleName);
	}

	LRESULT BaseTabControl::insertTextAndImage(size_t index, const wstring& text, const filesystem::path& pathToImage, const function<void()>& onClick)
	{
		if (!filesystem::exists(pathToImage))
		{
			throw exceptions::FileDoesNotExist(pathToImage, __FILE__, __FUNCTION__, __LINE__);
		}

		TCITEMW item = {};

		if (!images.contains(pathToImage))
		{
			images.addImage(pathToImage);
		}

		item.mask = TCIF_TEXT | TCIF_IMAGE;
		item.pszText = const_cast<wchar_t*>(text.data());
		item.cchTextMax = static_cast<int>(text.size());
		item.iImage = images[pathToImage];

		LRESULT result = SendMessageW(handle, TCM_INSERTITEM, index, reinterpret_cast<LPARAM>(&item));

		if (result != -1)
		{
			auto it = callbacks.insert(callbacks.begin() + index, onClick);

			tabs.emplace(tabs.begin() + index, text, pathToImage, *it);
		}

		return result;
	}

	LRESULT BaseTabControl::insertTextAndImage(size_t index, const wstring& text, const filesystem::path& pathToImage, const string& functionName, const string& moduleName)
	{
		if (!filesystem::exists(pathToImage))
		{
			throw exceptions::FileDoesNotExist(pathToImage, __FILE__, __FUNCTION__, __LINE__);
		}

		TCITEMW item = {};

		if (!images.contains(pathToImage))
		{
			images.addImage(pathToImage);
		}

		item.mask = TCIF_TEXT | TCIF_IMAGE;
		item.pszText = const_cast<wchar_t*>(text.data());
		item.cchTextMax = static_cast<int>(text.size());
		item.iImage = images[pathToImage];

		LRESULT result = SendMessageW(handle, TCM_INSERTITEM, index, reinterpret_cast<LPARAM>(&item));

		if (result != -1)
		{
			onClickSignature tem = reinterpret_cast<onClickSignature>(GetProcAddress(GUIFramework::get().getModules().at(moduleName), functionName.data()));

			if (!tem)
			{
				throw exceptions::CantFindFunctionFromModuleException(functionName, moduleName, __FILE__, __FUNCTION__, __LINE__);
			}

			callbacks.insert(callbacks.begin() + index, tem);

			tabs.emplace(tabs.begin() + index, text, pathToImage, functionName, moduleName);
		}

		return result;
	}

	bool BaseTabControl::removeTab(size_t index)
	{
		bool result = SendMessageW(handle, TCM_DELETEITEM, static_cast<WPARAM>(index), NULL);

		if (result)
		{
			callbacks.erase(callbacks.begin() + index);

			tabs.erase(tabs.begin() + index);
		}

		return result;
	}

	bool BaseTabControl::clear()
	{
		bool result = SendMessageW(handle, TCM_DELETEALLITEMS, NULL, NULL);

		if (result)
		{
			callbacks.clear();

			tabs.clear();
		}

		return result;
	}

	size_t BaseTabControl::size() const
	{
		return SendMessageW(handle, TCM_GETITEMCOUNT, NULL, NULL);
	}

	bool BaseTabControl::setItem(size_t index, const function<void()>& callback, const wstring& text, const filesystem::path& pathToImage)
	{
		if (!pathToImage.empty() && !filesystem::exists(pathToImage))
		{
			throw exceptions::FileDoesNotExist(pathToImage, __FILE__, __FUNCTION__, __LINE__);
		}

		TCITEMW item = {};

		if (text.size())
		{
			item.mask |= TCIF_TEXT;

			item.pszText = const_cast<wchar_t*>(text.data());
			item.cchTextMax = static_cast<int>(text.size());
		}

		if (!pathToImage.empty())
		{
			if (!images.contains(pathToImage))
			{
				images.addImage(pathToImage);
			}

			item.mask |= TCIF_IMAGE;

			item.iImage = images[pathToImage];
		}

		bool result = SendMessageW(handle, TCM_SETITEM, index, reinterpret_cast<LPARAM>(&item));

		if (result)
		{
			callbacks[index] = callback;

			tabs[index] = tabData(text, pathToImage, callback);
		}

		return result;
	}

	bool BaseTabControl::setItem(size_t index, const string& functionName, const string& moduleName, const wstring& text, const filesystem::path& pathToImage)
	{
		GUIFramework& instance = GUIFramework::get();
		const HMODULE& module = instance.getModules().at(moduleName);

		onClickSignature tem = reinterpret_cast<onClickSignature>(GetProcAddress(module, functionName.data()));

		if (!tem)
		{
			throw exceptions::CantFindFunctionFromModuleException(functionName, moduleName, __FILE__, __FUNCTION__, __LINE__);
		}

		if (!pathToImage.empty() && !filesystem::exists(pathToImage))
		{
			throw exceptions::FileDoesNotExist(pathToImage, __FILE__, __FUNCTION__, __LINE__);
		}

		TCITEMW item = {};

		if (text.size())
		{
			item.mask |= TCIF_TEXT;

			item.pszText = const_cast<wchar_t*>(text.data());
			item.cchTextMax = static_cast<int>(text.size());
		}

		if (!pathToImage.empty())
		{
			if (!images.contains(pathToImage))
			{
				images.addImage(pathToImage);
			}

			item.mask |= TCIF_IMAGE;

			item.iImage = images[pathToImage];
		}

		bool result = SendMessageW(handle, TCM_SETITEM, index, reinterpret_cast<LPARAM>(&item));

		if (result)
		{
			callbacks[index] = tem;

			tabs[index] = tabData(text, pathToImage, functionName, moduleName);
		}

		return result;
	}

	LRESULT BaseTabControl::setSelection(size_t index)
	{
		return SendMessageW(handle, TCM_SETCURSEL, static_cast<WPARAM>(index), NULL);
	}

	const BaseTabControl::tabData& BaseTabControl::getItem(size_t index) const
	{
		return tabs.at(index);
	}

	LRESULT BaseTabControl::getSelectedTab() const
	{
		return SendMessageW(handle, TCM_GETCURSEL, NULL, NULL);
	}

	uint16_t BaseTabControl::getImagesWidth() const
	{
		return images.getImagesWidth();
	}

	uint16_t BaseTabControl::getImagesHeight() const
	{
		return images.getImagesHeight();
	}

	void BaseTabControl::setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		__utility::throwNotImplementedException(__FUNCTION__, "BaseTabControl"sv);
	}

	void BaseTabControl::setTextColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		__utility::throwNotImplementedException(__FUNCTION__, "BaseTabControl"sv);
	}

	json::JSONBuilder BaseTabControl::getStructure() const
	{
		using json::utility::jsonObject;

		json::JSONBuilder builder = BaseComponent::getStructure();
		jsonObject& current = get<jsonObject>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);
		vector<jsonObject> jsonTabs;

		current.data.push_back({ "imagesWidth"s, static_cast<uint64_t>(images.getImagesWidth()) });

		current.data.push_back({ "imagesHeight"s, static_cast<uint64_t>(images.getImagesHeight()) });

		auto serializeText = [this](jsonObject& object, const tabData& data)
		{
			if (data.text.empty())
			{
				return;
			}

			object.data.push_back({ "tabText"s, utility::to_string(data.text, ISerializable::getCodepage()) });
		};
		auto serializePathToImage = [](jsonObject& object, const tabData& data)
		{
			if (data.pathToImage.empty())
			{
				return;
			}

			object.data.push_back({ "tabImagePath"s, data.pathToImage.string() });
		};
		auto serializeCallback = [](jsonObject& object, const tabData& data)
		{
			object.data.push_back({ "functionName"s, data.functionName });
			object.data.push_back({ "moduleName"s, data.moduleName });
			object.data.push_back({ "pathToModule"s, GUIFramework::get().getModulesPaths().at(data.moduleName) });
		};

		for (const auto& i : tabs)
		{
			jsonObject object;

			if (i.functionName.size())
			{
				serializeText(object, i);

				serializePathToImage(object, i);

				serializeCallback(object, i);

				json::utility::appendArray(move(object), jsonTabs);
			}
			else
			{
				serializeText(object, i);

				serializePathToImage(object, i);

				json::utility::appendArray(move(object), jsonTabs);
			}
		}

		current.data.push_back({ "tabs"s, move(jsonTabs) });

		return builder;
	}
}
