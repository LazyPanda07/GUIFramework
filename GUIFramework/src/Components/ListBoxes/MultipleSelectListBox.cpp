#include "headers.h"
#include "MultipleSelectListBox.h"

using namespace std;

namespace gui_framework
{
	MultipleSelectListBox::MultipleSelectListBox(const wstring& listBoxName, const utility::ComponentSettings& settings, BaseComponent* parent, bool isSorting) :
		BaseMultipleSelectListBox
		(
			listBoxName,
			settings,
			parent
		)
	{
		if (isSorting)
		{
			utility::appendStyle(handle, LBS_SORT);
		}
	}

	size_t MultipleSelectListBox::getHash() const
	{
		return typeid(MultipleSelectListBox).hash_code();
	}

	json::JSONBuilder MultipleSelectListBox::getStructure() const
	{
		using json::utility::jsonObject;
		using json::utility::objectSmartPointer;

		json::JSONBuilder builder = BaseMultipleSelectListBox::getStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		return builder;
	}
}
