#include "pch.h"
#include "BaseMultipleSelectListBox.h"

#include "Exceptions/SelectListException.h"

#pragma push_macro("min")
#undef min

using namespace std;

namespace gui_framework
{
	BaseMultipleSelectListBox::BaseMultipleSelectListBox(const wstring& listBoxName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseComponent
		(
			wstring(standard_classes::listBox),
			listBoxName,
			settings,
			parent
		),
		BaseListBox
		(
			listBoxName, 
			utility::ComponentSettings
			(
				settings.styles | LBS_MULTIPLESEL,
				settings.x,
				settings.y,
				settings.width,
				settings.height,
				settings.id,
				settings.extendedStyles
			),
			parent
		)
	{

	}

	LRESULT BaseMultipleSelectListBox::getCurrentSelections() const
	{
		LRESULT result = SendMessageW(handle, LB_GETSELCOUNT, NULL, NULL);

		if (result == LB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, result);
		}

		return result;
	}

	vector<wstring> BaseMultipleSelectListBox::getSelectedItems() const
	{
		WPARAM itemsCount = this->getCurrentSelections();
		vector<wstring> items;
		vector<int> indices(itemsCount);

		LRESULT result = SendMessageW(handle, LB_GETSELITEMS, itemsCount, reinterpret_cast<LPARAM>(indices.data()));

		if (result == LB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, result);
		}

		items.reserve(itemsCount);

		for (const auto& i : indices)
		{
			items.push_back(this->getValue(i));
		}

		return items;
	}

	void BaseMultipleSelectListBox::selectMultipleItems(WPARAM firstItemIndex, LPARAM lastItemIndex) const
	{
		if (SendMessageW(handle, LB_SELITEMRANGEEX, firstItemIndex, lastItemIndex) == LB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, LB_ERR);
		}
	}

	LRESULT BaseMultipleSelectListBox::setCurrentSelection(LRESULT index) const
	{
		LRESULT result = SendMessageW(handle, LB_SETSEL, true, index);

		if (result == LB_ERR)
		{
			throw exceptions::SelectListException(__FUNCTION__, result);
		}

		return result;
	}
}

#pragma pop_macro("min")
