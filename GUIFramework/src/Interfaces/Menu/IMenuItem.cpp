#include "pch.h"
#include "IMenuItem.h"

using namespace std;

namespace gui_framework
{
	namespace interfaces
	{
		IMenuItem::IMenuItem(const string& type) :
			parent(nullptr),
			index(0),
			type(type)
		{

		}

		void IMenuItem::setParent(HMENU parent)
		{
			this->parent = parent;
		}

		void IMenuItem::setIndex(uint32_t index)
		{
			this->index = index;
		}

		const string& IMenuItem::getMenuType() const
		{
			return type;
		}

		IMenuItem::~IMenuItem()
		{
			DeleteMenu(parent, index, MF_BYPOSITION);
		}
	}
}
