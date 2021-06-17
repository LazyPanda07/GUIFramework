#include "pch.h"
#include "IMenuItem.h"

using namespace std;

namespace gui_framework
{
	namespace interfaces
	{
		IMenuItem::IMenuItem(const wstring& text, const string& type) :
			text(text),
			type(type),
			parent(nullptr),
			index(0)
		{

		}

		void IMenuItem::createMenuItem(HMENU parent)
		{
			this->setParent(parent);

			auto [styles, value] = this->getCreationData();

			AppendMenuW(parent, styles | MF_STRING, value, text.data());
		}

		void IMenuItem::setParent(HMENU parent)
		{
			this->parent = parent;
		}

		void IMenuItem::setIndex(uint32_t index)
		{
			this->index = index;
		}

		const wstring& IMenuItem::getText() const
		{
			return text;
		}

		const string& IMenuItem::getType() const
		{
			return type;
		}

		IMenuItem::~IMenuItem()
		{
			DeleteMenu(parent, index, MF_BYPOSITION);
		}
	}
}
