#include "pch.h"
#include "BaseMultipleSelectListBox.h"

#include "Styles/Components/ListBoxes/MultipleSelectListBoxStyles.h"
#include "Exceptions/SelectListException.h"

#pragma push_macro("min")
#undef min

using namespace std;

namespace gui_framework
{
	BaseMultipleSelectListBox::BaseMultipleSelectListBox(const wstring& listBoxName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseListBox
		(
			listBoxName, 
			settings,
			styles::MultipleSelectListBoxStyles(),
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

	json::JSONBuilder BaseMultipleSelectListBox::getStructure() const
	{
		using json::utility::jsonObject;
		using json::utility::objectSmartPointer;

		json::JSONBuilder builder = BaseComponent::getStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);
		
		__utility::changeClassName(current, "MultipleSelectListBox");

		return builder;
	}
}

#pragma pop_macro("min")
