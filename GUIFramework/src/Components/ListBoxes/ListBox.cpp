#include "headers.h"
#include "ListBox.h"

#include "Styles/Components/ListBoxes/DefaultListBoxStyles.h"

using namespace std;

namespace gui_framework
{
	ListBox::ListBox(const wstring& listBoxName, const utility::ComponentSettings& settings, BaseComponent* parent, bool isSorting) :
		BaseListBox
		(
			listBoxName,
			settings,
			styles::DefaultListBoxStyles(isSorting),
			parent
		)
	{
		
	}

	size_t ListBox::getHash() const
	{
		return typeid(ListBox).hash_code();
	}
}
