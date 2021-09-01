#include "headers.h"
#include "BaseListBox.h"

#include "Exceptions/SelectListException.h"

#pragma push_macro("min")
#pragma push_macro("max")
#undef min
#undef max

using namespace std;

namespace gui_framework
{
	BaseListBox::BaseListBox(const wstring& listBoxName, const utility::ComponentSettings& settings, const styles::ListBoxStyles& styles, BaseComponent* parent) :
		BaseComponent
		(
			wstring(standard_classes::listBox),
			listBoxName,
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
		requiredSize{ settings.width, settings.height },
		columnsWidth(0)
	{

	}

	LRESULT BaseListBox::addValue(const wstring& value)
	{
		LRESULT result = SendMessageW(handle, LB_ADDSTRING, NULL, reinterpret_cast<LPARAM>(value.data()));

		if (result == LB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, result);
		}
		else if (result == LB_ERRSPACE)
		{
			throw exceptions::SelectListException(__FUNCTION__, result, exception_messages::notEnoughSpace);
		}

		this->resize(BaseComponent::parent->getActualWidth(), BaseComponent::parent->getActualHeight());

		return result;
	}

	LRESULT BaseListBox::removeValue(size_t index)
	{
		LRESULT result = SendMessageW(handle, LB_DELETESTRING, index, NULL);

		if (result == LB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, result);
		}

		this->resize(BaseComponent::parent->getActualWidth(), BaseComponent::parent->getActualHeight());

		return result;
	}

	LRESULT BaseListBox::insertValue(const wstring& value, LRESULT index)
	{
		LRESULT result = SendMessageW(handle, LB_INSERTSTRING, index, reinterpret_cast<LPARAM>(value.data()));

		if (result == LB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, result);
		}
		else if (result == LB_ERRSPACE)
		{
			throw exceptions::SelectListException(__FUNCTION__, result, exception_messages::notEnoughSpace);
		}

		this->resize(BaseComponent::parent->getActualWidth(), BaseComponent::parent->getActualHeight());

		return result;
	}

	LRESULT BaseListBox::changeValue(const wstring& newValue, LRESULT index)
	{
		LRESULT result = SendMessageW(handle, LB_SETITEMDATA, index, reinterpret_cast<LPARAM>(newValue.data()));

		if (result == LB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, result);
		}

		this->resize(BaseComponent::parent->getActualWidth(), BaseComponent::parent->getActualHeight());

		return result;
	}

	LRESULT BaseListBox::findSubstring(const wstring& subStringToFind)
	{
		LRESULT findedIndex = SendMessageW(handle, LB_FINDSTRING, 0, reinterpret_cast<LPARAM>(subStringToFind.data()));

		if (findedIndex == LB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, findedIndex);
		}

		return findedIndex;
	}

	LRESULT BaseListBox::findString(const wstring& stringToFind)
	{
		LRESULT findedIndex = SendMessageW(handle, LB_FINDSTRINGEXACT, 0, reinterpret_cast<LPARAM>(stringToFind.data()));

		if (findedIndex == LB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, findedIndex);
		}

		return findedIndex;
	}

	wstring BaseListBox::getValue(size_t index) const
	{
		wstring result;
		LRESULT size = SendMessageW(handle, LB_GETTEXTLEN, index, NULL);

		if (size == LB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, size);
		}

		result.resize(++size);

		LRESULT errorCode = SendMessageW(handle, LB_GETTEXT, index, reinterpret_cast<LPARAM>(result.data()));

		if (errorCode == LB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, errorCode);
		}

		result.pop_back();

		return result;
	}

	LRESULT BaseListBox::getCurrentSelectionIndex() const
	{
		return SendMessageW(handle, LB_GETCURSEL, NULL, NULL);
	}

	LRESULT BaseListBox::setCurrentSelection(LRESULT index) const
	{
		LRESULT result = SendMessageW(handle, LB_SETCURSEL, index, NULL);

		if (result == LB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, result);
		}

		return result;
	}

	LRESULT BaseListBox::size() const
	{
		LRESULT result = SendMessageW(handle, LB_GETCOUNT, NULL, NULL);

		if (result == LB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, result);
		}

		return result;
	}

	void BaseListBox::clear()
	{
		SendMessageW(handle, LB_RESETCONTENT, NULL, NULL);
	}

	LRESULT BaseListBox::setItemsHeight(uint8_t height)
	{
		LRESULT result = SendMessageW(handle, LB_SETITEMHEIGHT, NULL, height);

		if (result == LB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, result);
		}

		return result;
	}

	LRESULT BaseListBox::setColumnsWidth(uint8_t width)
	{
		LRESULT result = SendMessageW(handle, LB_SETCOLUMNWIDTH, width, NULL);

		if (result == LB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, result);
		}

		columnsWidth = width;

		return result;
	}

	LRESULT BaseListBox::getItemsHeight() const
	{
		LRESULT result = SendMessageW(handle, LB_GETITEMHEIGHT, NULL, NULL);

		if (result == LB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, result);
		}

		return result;
	}

	uint8_t BaseListBox::getColumnsWidth() const
	{
		return columnsWidth;
	}

	void BaseListBox::resize(uint16_t width, uint16_t height)
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
					static_cast<int>(desiredWidth * widthCoefficient + standard_sizes::listBoxAdditionalWidth),
					desiredHeight,
					true
				);

				ShowWindow(handle, SW_SHOW);

				return;
			}

			for (size_t i = 0; i < static_cast<size_t>(currentSize); i++)
			{
				wstring value = this->getValue(i);
				SIZE valueSizes;

				if (GetTextExtentPoint32W(deviceContext, value.data(), static_cast<int>(value.size()), &valueSizes))
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

			uint16_t newHeight = 0;

			if (heightSum > desiredHeight)
			{
				utility::appendStyle(handle, WS_VSCROLL);

				newHeight = desiredHeight;
			}
			else
			{
				utility::removeStyle(handle, WS_VSCROLL);

				this->setItemsHeight(static_cast<uint8_t>(requiredSize.cy));

				newHeight = static_cast<uint16_t>(heightSum + requiredSize.cy * 2);
			}

			MoveWindow
			(
				handle,
				static_cast<int>(desiredX * (static_cast<double>(width) / parentWidth)),
				static_cast<int>(desiredY * (static_cast<double>(height) / parentHeight)),
				max(requiredSize.cx + standard_sizes::listBoxAdditionalWidth, static_cast<long>(desiredWidth * (static_cast<double>(width) / parentWidth) + standard_sizes::listBoxAdditionalWidth)),
				newHeight,
				true
			);

			ShowWindow(handle, SW_SHOW);
		}
	}

	json::JSONBuilder BaseListBox::getStructure() const
	{
		using json::utility::jsonObject;
		using json::utility::objectSmartPointer;

		uint32_t codepage = ISerializable::getCodepage();
		json::JSONBuilder builder = BaseComponent::getStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, codepage)]);
		vector<objectSmartPointer<jsonObject>> values;
		LRESULT currentSize = this->size();

		current->data.push_back({ "columnWidth"s, static_cast<uint64_t>(columnsWidth) });

		if (currentSize > 0)
		{
			for (size_t i = 0; i < static_cast<size_t>(currentSize); i++)
			{
				json::utility::appendArray(utility::to_string(this->getValue(i), codepage), values);
			}

			current->data.push_back({ "listBoxValues"s, move(values) });
		}

		return builder;
	}
}

#pragma pop_macro("min")
#pragma pop_macro("max")
