#include "pch.h"
#include "BaseComboBox.h"

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

		this->resize(NULL, NULL);

		return result;
	}

	LRESULT BaseComboBox::removeValue(size_t index)
	{
		LRESULT result = SendMessageW(handle, CB_DELETESTRING, index, NULL);

		this->resize(NULL, NULL);

		return result;
	}

	LRESULT BaseComboBox::insertValue(const wstring& value, LRESULT index)
	{
		LRESULT result = SendMessageW(handle, CB_INSERTSTRING, index, reinterpret_cast<LPARAM>(value.data()));

		this->resize(NULL, NULL);

		return result;
	}

	LRESULT BaseComboBox::changeValue(const wstring& newValue, LRESULT index)
	{
		LRESULT result = SendMessageW(handle, CB_SETITEMDATA, index, reinterpret_cast<LPARAM>(newValue.data()));

		this->resize(NULL, NULL);

		return result;
	}

	wstring BaseComboBox::findSubString(const wstring& subStringToFind)
	{
		LRESULT findedIndex = SendMessageW(handle, CB_FINDSTRING, 0, reinterpret_cast<LPARAM>(subStringToFind.data()));

		return this->getValue(findedIndex);
	}

	wstring BaseComboBox::findString(const wstring& stringToFind)
	{
		LRESULT findedIndex = SendMessageW(handle, CB_FINDSTRINGEXACT, 0, reinterpret_cast<LPARAM>(stringToFind.data()));

		return this->getValue(findedIndex);
	}

	wstring BaseComboBox::getValue(size_t index) const
	{
		wstring result;
		LRESULT size = SendMessageW(handle, CB_GETLBTEXTLEN, index, NULL);

		result.resize(++size);

		SendMessageW(handle, CB_GETLBTEXT, index, reinterpret_cast<LPARAM>(result.data()));

		result.pop_back();

		return result;
	}

	LRESULT BaseComboBox::getCurrentSelectionIndex() const
	{
		return SendMessageW(handle, CB_GETCURSEL, NULL, NULL);
	}

	LRESULT BaseComboBox::setCurrentSelection(LRESULT index) const
	{
		return SendMessageW(handle, CB_SETCURSEL, index, NULL);
	}

	LRESULT BaseComboBox::size() const
	{
		return SendMessageW(handle, CB_GETCOUNT, NULL, NULL);
	}

	void BaseComboBox::clear()
	{
		SendMessageW(handle, CB_RESETCONTENT, NULL, NULL);
	}

	LRESULT BaseComboBox::setItemHeight(itemHeightEnum value, uint16_t height)
	{
		return SendMessageW(handle, CB_SETITEMHEIGHT, static_cast<WPARAM>(value), height);
	}

	LRESULT BaseComboBox::setDroppedWidth(uint16_t width)
	{
		return SendMessageW(handle, CB_SETDROPPEDWIDTH, width, NULL);
	}

	LRESULT BaseComboBox::getItemHeight(itemHeightEnum value) const
	{
		return SendMessageW(handle, CB_GETITEMHEIGHT, static_cast<WPARAM>(value), NULL);
	}

	LRESULT BaseComboBox::getDroppedWidth() const
	{
		return SendMessageW(handle, CB_GETDROPPEDWIDTH, NULL, NULL);
	}

	void BaseComboBox::resize(uint16_t width, uint16_t height)
	{
		if (autoResize && !blockResize)
		{
			LRESULT currentSize = this->size();
			HDC deviceContext = GetDC(handle);

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
				}
			}

			this->setItemHeight(itemHeightEnum::forAllItems, static_cast<uint16_t>(requiredSize.cy));
			
			MoveWindow
			(
				handle,
				desiredX,
				desiredY,
				requiredSize.cx,
				desiredHeight,
				true
			);

			ShowWindow(handle, SW_SHOW);
		}
	}
}

#pragma pop_macro("min")
