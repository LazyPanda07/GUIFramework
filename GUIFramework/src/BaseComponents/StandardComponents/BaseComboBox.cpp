#include "pch.h"
#include "BaseComboBox.h"

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
		)
	{

	}

	LRESULT BaseComboBox::addValue(const wstring& value)
	{
		return SendMessageW(handle, CB_ADDSTRING, NULL, reinterpret_cast<LPARAM>(value.data()));
	}

	LRESULT BaseComboBox::removeValue(size_t index)
	{
		return SendMessageW(handle, CB_DELETESTRING, index, NULL);
	}

	LRESULT BaseComboBox::insertValue(const wstring& value, LRESULT index)
	{
		return SendMessageW(handle, CB_INSERTSTRING, index, reinterpret_cast<LPARAM>(value.data()));
	}

	LRESULT BaseComboBox::changeValue(const wstring& newValue, LRESULT index)
	{
		return SendMessageW(handle, CB_SETITEMDATA, index, reinterpret_cast<LPARAM>(newValue.data()));
	}

	wstring BaseComboBox::findSubString(const wstring& subStringToFind)
	{
		LRESULT findedIndex = SendMessageW(handle, CB_FINDSTRING, 0, reinterpret_cast<LPARAM>(subStringToFind.data()));
		wstring result;

		LRESULT size = SendMessageW(handle, CB_GETLBTEXTLEN, findedIndex, NULL);

		result.resize(++size);

		SendMessageW(handle, CB_GETLBTEXT, findedIndex, reinterpret_cast<LPARAM>(result.data()));

		result.pop_back();

		return result;
	}

	wstring BaseComboBox::findString(const wstring& stringToFind)
	{
		LRESULT findedIndex = SendMessageW(handle, CB_FINDSTRINGEXACT, 0, reinterpret_cast<LPARAM>(stringToFind.data()));
		wstring result;

		LRESULT size = SendMessageW(handle, CB_GETLBTEXTLEN, findedIndex, NULL);

		result.resize(++size);

		SendMessageW(handle, CB_GETLBTEXT, findedIndex, reinterpret_cast<LPARAM>(result.data()));

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

		}
	}
}
