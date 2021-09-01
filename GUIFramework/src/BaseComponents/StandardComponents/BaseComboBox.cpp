#include "headers.h"
#include "BaseComboBox.h"

#include "Exceptions/SelectListException.h"
#include "Exceptions/NotImplemented.h"
#include "Exceptions/CantFindFunctionFromModuleException.h"

#pragma warning(disable: 4018)
#pragma warning(disable: 4267)

#pragma push_macro("min")
#pragma push_macro("max")
#undef min
#undef max

using namespace std;

namespace gui_framework
{
	LRESULT BaseComboBox::windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		if (message == WM_COMMAND && id == LOWORD(wparam))
		{
			switch (HIWORD(wparam))
			{
			case CBN_SELCHANGE:
				if (onSelectionChange)
				{
					isUsed = true;

					onSelectionChange(*this);
				}

				return 0;

			default:
				break;
			}
		}

		isUsed = false;

		return -1;
	}

	void BaseComboBox::loadOnSelectionChangeFromModule(function<void(BaseComboBox&)>& onSelectionChange, const string& functionName, const string& moduleName)
	{
		GUIFramework& instance = GUIFramework::get();
		const HMODULE& module = instance.getModules().at(moduleName);

		comboBoxCallbackSignature tem = reinterpret_cast<comboBoxCallbackSignature>(GetProcAddress(module, functionName.data()));

		if (!tem)
		{
			throw exceptions::CantFindFunctionFromModuleException(functionName, moduleName);
		}

		onSelectionChange = tem;
	}

	BaseComboBox::BaseComboBox(const wstring& comboBoxName, const utility::ComponentSettings& settings, const styles::ComboBoxStyles& styles, BaseComponent* parent) :
		BaseComponent
		(
			wstring(standard_classes::comboBox),
			comboBoxName,
			settings,
			styles,
			parent
		),
		IResizableComponent
		(
			handle,
			parent ? parent->getHandle() : nullptr,
			true
		),
		requiredSize{ settings.width, settings.height }
	{

	}

	LRESULT BaseComboBox::addValue(const wstring& value)
	{
		LRESULT result = SendMessageW(handle, CB_ADDSTRING, NULL, reinterpret_cast<LPARAM>(value.data()));

		if (result == CB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, result);
		}
		else if (result == CB_ERRSPACE)
		{
			throw exceptions::SelectListException(__FUNCTION__, result, exception_messages::notEnoughSpace);
		}

		this->resize(NULL, NULL);

		return result;
	}

	LRESULT BaseComboBox::removeValue(size_t index)
	{
		LRESULT result = SendMessageW(handle, CB_DELETESTRING, index, NULL);

		if (result == CB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, result);
		}

		this->resize(NULL, NULL);

		return result;
	}

	LRESULT BaseComboBox::insertValue(const wstring& value, LRESULT index)
	{
		LRESULT result = SendMessageW(handle, CB_INSERTSTRING, index, reinterpret_cast<LPARAM>(value.data()));

		if (result == CB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, result);
		}
		else if (result == CB_ERRSPACE)
		{
			throw exceptions::SelectListException(__FUNCTION__, result, exception_messages::notEnoughSpace);
		}

		this->resize(NULL, NULL);

		return result;
	}

	LRESULT BaseComboBox::changeValue(const wstring& newValue, LRESULT index)
	{
		LRESULT result = SendMessageW(handle, CB_SETITEMDATA, index, reinterpret_cast<LPARAM>(newValue.data()));

		if (result == CB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, result);
		}

		this->resize(NULL, NULL);

		return result;
	}

	LRESULT BaseComboBox::findSubstring(const wstring& substringToFind)
	{
		LRESULT findedIndex = SendMessageW(handle, CB_FINDSTRING, 0, reinterpret_cast<LPARAM>(substringToFind.data()));

		if (findedIndex == CB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, findedIndex);
		}

		return findedIndex;
	}

	LRESULT BaseComboBox::findString(const wstring& stringToFind)
	{
		LRESULT findedIndex = SendMessageW(handle, CB_FINDSTRINGEXACT, 0, reinterpret_cast<LPARAM>(stringToFind.data()));

		if (findedIndex == CB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, findedIndex);
		}

		return findedIndex;
	}

	wstring BaseComboBox::getValue(size_t index) const
	{
		wstring result;
		LRESULT size = SendMessageW(handle, CB_GETLBTEXTLEN, index, NULL);

		if (size == CB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, size);
		}

		result.resize(++size);

		LRESULT errorCode = SendMessageW(handle, CB_GETLBTEXT, index, reinterpret_cast<LPARAM>(result.data()));

		if (errorCode == CB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, errorCode);
		}

		result.pop_back();

		return result;
	}

	LRESULT BaseComboBox::getCurrentSelectionIndex() const
	{
		return SendMessageW(handle, CB_GETCURSEL, NULL, NULL);
	}

	LRESULT BaseComboBox::setCurrentSelection(LRESULT index) const
	{
		LRESULT result = SendMessageW(handle, CB_SETCURSEL, index, NULL);

		if (result == CB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, result);
		}

		return result;
	}

	LRESULT BaseComboBox::size() const
	{
		LRESULT result = SendMessageW(handle, CB_GETCOUNT, NULL, NULL);

		if (result == CB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, result);
		}

		return result;
	}

	void BaseComboBox::clear()
	{
		SendMessageW(handle, CB_RESETCONTENT, NULL, NULL);
	}

	void BaseComboBox::setSortingMode(bool isSorting)
	{
		isSorting ?
			SetWindowLongPtrW(handle, GWL_STYLE, GetWindowLongPtrW(handle, GWL_STYLE) | CBS_SORT) :
			SetWindowLongPtrW(handle, GWL_STYLE, GetWindowLongPtrW(handle, GWL_STYLE) ^ CBS_SORT);
	}

	LRESULT BaseComboBox::setItemHeight(itemHeightEnum value, uint16_t height)
	{
		LRESULT result = SendMessageW(handle, CB_SETITEMHEIGHT, static_cast<WPARAM>(value), height);

		if (result == CB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, result);
		}

		return result;
	}

	LRESULT BaseComboBox::setDroppedWidth(uint16_t width)
	{
		LRESULT result = SendMessageW(handle, CB_SETDROPPEDWIDTH, width, NULL);

		if (result == CB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, result);
		}

		return result;
	}

	void BaseComboBox::setOnSelectionChange(const function<void(BaseComboBox&)>& onSelectionChange)
	{
		this->onSelectionChange = onSelectionChange;

		functionName.clear();
		moduleName.clear();
	}

	void BaseComboBox::setOnSelectionChange(const string& functionName, const string& moduleName)
	{
		GUIFramework& instance = GUIFramework::get();
		const HMODULE& module = instance.getModules().at(moduleName);

		comboBoxCallbackSignature tem = reinterpret_cast<comboBoxCallbackSignature>(GetProcAddress(module, functionName.data()));

		if (!tem)
		{
			throw exceptions::CantFindFunctionFromModuleException(functionName, moduleName);
		}

		onSelectionChange = tem;

		this->functionName = functionName;
		this->moduleName = moduleName;
	}

	LRESULT BaseComboBox::getItemHeight(itemHeightEnum value) const
	{
		LRESULT result = SendMessageW(handle, CB_GETITEMHEIGHT, static_cast<WPARAM>(value), NULL);

		if (result == CB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, result);
		}

		return result;
	}

	LRESULT BaseComboBox::getDroppedWidth() const
	{
		LRESULT result = SendMessageW(handle, CB_GETDROPPEDWIDTH, NULL, NULL);

		if (result == CB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, result);
		}

		return result;
	}

	void BaseComboBox::resize(uint16_t width, uint16_t height)
	{
		if (autoResize && !blockResize)
		{
			LRESULT currentSize = this->size();
			HDC deviceContext = GetDC(handle);
			int heightSum = 0;

			if (currentSize == CB_ERR || !currentSize)
			{
				double widthCoefficient = static_cast<double>(width) / parentWidth;

				MoveWindow
				(
					handle,
					static_cast<int>(desiredX * widthCoefficient),
					static_cast<int>(desiredY * (static_cast<double>(height) / parentHeight)),
					desiredWidth,
					static_cast<int>(desiredHeight * widthCoefficient),
					true
				);

				ShowWindow(handle, SW_SHOW);

				return;
			}

			for (size_t i = 0; i < currentSize; i++)
			{
				wstring value = this->getValue(i);
				SIZE valueSizes;

				if (GetTextExtentPoint32W(deviceContext, value.data(), value.size(), &valueSizes))
				{
					if (valueSizes.cx > requiredSize.cx)
					{
						requiredSize.cx = valueSizes.cx;
					}

					if (valueSizes.cy > requiredSize.cy)
					{
						requiredSize.cy = valueSizes.cy;
					}

					heightSum += valueSizes.cy;
				}
			}

			this->setItemHeight(itemHeightEnum::forAllItems, static_cast<uint16_t>(requiredSize.cy));

			MoveWindow
			(
				handle,
				static_cast<int>(desiredX * (static_cast<double>(width) / parentWidth)),
				static_cast<int>(desiredY * (static_cast<double>(height) / parentHeight)),
				max(requiredSize.cx + standard_sizes::comboBoxAdditionalWidth, static_cast<long>(desiredWidth * (static_cast<double>(width) / parentWidth))),
				heightSum + requiredSize.cy * 2,
				true
			);
		}
	}

	void BaseComboBox::setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		__utility::throwNotImplementedException(__FUNCTION__, "BaseComboBox"sv);
	}

	void BaseComboBox::setTextColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		__utility::throwNotImplementedException(__FUNCTION__, "BaseComboBox"sv);
	}

	json::JSONBuilder BaseComboBox::getStructure() const
	{
		using json::utility::jsonObject;
		using json::utility::objectSmartPointer;

		uint32_t codepage = ISerializable::getCodepage();
		json::JSONBuilder builder = BaseComponent::getStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, codepage)]);
		vector<objectSmartPointer<jsonObject>> values;
		LRESULT currentSize = this->size();

		if (functionName.size())
		{
			current->data.push_back({ "functionName"s, functionName });

			current->data.push_back({ "moduleName"s, moduleName });

			current->data.push_back({ "pathToModule"s, GUIFramework::get().getModulesPaths().at(moduleName) });
		}

		if (currentSize > 0)
		{
			for (size_t i = 0; i < static_cast<size_t>(currentSize); i++)
			{
				json::utility::appendArray(utility::to_string(this->getValue(i), codepage), values);
			}

			current->data.push_back({ "comboBoxValues"s, move(values) });
		}

		return builder;
	}
}

#pragma pop_macro("min")
#pragma pop_macro("max")
