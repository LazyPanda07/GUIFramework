#include "pch.h"
#include "BaseComboBox.h"

#include "Exceptions/ComboBoxException.h"

#pragma warning(disable: 4018)
#pragma warning(disable: 4267)

#pragma push_macro("min")
#undef min

using namespace std;

namespace gui_framework
{
	BaseComboBox::BaseComboBox(const wstring& comboBoxName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseComponent
		(
			wstring(standard_classes::comboBox),
			comboBoxName,
			settings,
			parent
		),
		IResizableComponent
		(
			handle,
			parent ? parent->getHandle() : nullptr,
			true
		),
		requiredSize{ numeric_limits<long>::min(), numeric_limits<long>::min() }
	{

	}

	LRESULT BaseComboBox::addValue(const wstring& value)
	{
		LRESULT result = SendMessageW(handle, CB_ADDSTRING, NULL, reinterpret_cast<LPARAM>(value.data()));

		if (result == CB_ERR)
		{
			throw exceptions::ComboBoxException(__FUNCTION__, result);
		}
		else if (result == CB_ERRSPACE)
		{
			throw exceptions::ComboBoxException(__FUNCTION__, result, exception_messages::notEnoughSpace);
		}

		this->resize(NULL, NULL);

		return result;
	}

	LRESULT BaseComboBox::removeValue(size_t index)
	{
		LRESULT result = SendMessageW(handle, CB_DELETESTRING, index, NULL);

		if (result == CB_ERR)
		{
			throw exceptions::ComboBoxException(__FUNCTION__, result);
		}

		this->resize(NULL, NULL);

		return result;
	}

	LRESULT BaseComboBox::insertValue(const wstring& value, LRESULT index)
	{
		LRESULT result = SendMessageW(handle, CB_INSERTSTRING, index, reinterpret_cast<LPARAM>(value.data()));

		if (result == CB_ERR)
		{
			throw exceptions::ComboBoxException(__FUNCTION__, result);
		}
		else if (result == CB_ERRSPACE)
		{
			throw exceptions::ComboBoxException(__FUNCTION__, result, exception_messages::notEnoughSpace);
		}

		this->resize(NULL, NULL);

		return result;
	}

	LRESULT BaseComboBox::changeValue(const wstring& newValue, LRESULT index)
	{
		LRESULT result = SendMessageW(handle, CB_SETITEMDATA, index, reinterpret_cast<LPARAM>(newValue.data()));

		if (result == CB_ERR)
		{
			throw exceptions::ComboBoxException(__FUNCTION__, result);
		}

		this->resize(NULL, NULL);

		return result;
	}

	wstring BaseComboBox::findSubString(const wstring& subStringToFind)
	{
		LRESULT findedIndex = SendMessageW(handle, CB_FINDSTRING, 0, reinterpret_cast<LPARAM>(subStringToFind.data()));

		if (findedIndex == CB_ERR)
		{
			throw exceptions::ComboBoxException(__FUNCTION__, findedIndex);
		}

		return this->getValue(findedIndex);
	}

	wstring BaseComboBox::findString(const wstring& stringToFind)
	{
		LRESULT findedIndex = SendMessageW(handle, CB_FINDSTRINGEXACT, 0, reinterpret_cast<LPARAM>(stringToFind.data()));

		if (findedIndex == CB_ERR)
		{
			throw exceptions::ComboBoxException(__FUNCTION__, findedIndex);
		}

		return this->getValue(findedIndex);
	}

	wstring BaseComboBox::getValue(size_t index) const
	{
		wstring result;
		LRESULT size = SendMessageW(handle, CB_GETLBTEXTLEN, index, NULL);

		if (size == CB_ERR)
		{
			throw exceptions::ComboBoxException(__FUNCTION__, size);
		}

		result.resize(++size);

		LRESULT errorCode = SendMessageW(handle, CB_GETLBTEXT, index, reinterpret_cast<LPARAM>(result.data()));

		if (errorCode == CB_ERR)
		{
			throw exceptions::ComboBoxException(__FUNCTION__, errorCode);
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
			throw exceptions::ComboBoxException(__FUNCTION__, result);
		}

		return result;
	}

	LRESULT BaseComboBox::size() const
	{
		LRESULT result = SendMessageW(handle, CB_GETCOUNT, NULL, NULL);

		if (result == CB_ERR)
		{
			throw exceptions::ComboBoxException(__FUNCTION__, result);
		}

		return result;
	}

	void BaseComboBox::clear()
	{
		SendMessageW(handle, CB_RESETCONTENT, NULL, NULL);
	}

	LRESULT BaseComboBox::setItemHeight(itemHeightEnum value, uint16_t height)
	{
		LRESULT result = SendMessageW(handle, CB_SETITEMHEIGHT, static_cast<WPARAM>(value), height);

		if (result == CB_ERR)
		{
			throw exceptions::ComboBoxException(__FUNCTION__, result);
		}

		return result;
	}

	LRESULT BaseComboBox::setDroppedWidth(uint16_t width)
	{
		LRESULT result = SendMessageW(handle, CB_SETDROPPEDWIDTH, width, NULL);

		if (result == CB_ERR)
		{
			throw exceptions::ComboBoxException(__FUNCTION__, result);
		}

		return result;
	}

	LRESULT BaseComboBox::getItemHeight(itemHeightEnum value) const
	{
		LRESULT result = SendMessageW(handle, CB_GETITEMHEIGHT, static_cast<WPARAM>(value), NULL);

		if (result == CB_ERR)
		{
			throw exceptions::ComboBoxException(__FUNCTION__, result);
		}

		return result;
	}

	LRESULT BaseComboBox::getDroppedWidth() const
	{
		LRESULT result = SendMessageW(handle, CB_GETDROPPEDWIDTH, NULL, NULL);

		if (result == CB_ERR)
		{
			throw exceptions::ComboBoxException(__FUNCTION__, result);
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

			if (currentSize == CB_ERR)
			{
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
				desiredX,
				desiredY,
				requiredSize.cx + standard_sizes::comboBoxAdditionalWidth,
				heightSum + requiredSize.cy * 2,
				true
			);

			ShowWindow(handle, SW_SHOW);
		}
	}
}

#pragma pop_macro("min")
