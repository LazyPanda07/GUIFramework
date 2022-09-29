#include "core.h"
#include "IMenuItem.h"

#include "Utility/Utility.h"

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

		json::JSONBuilder IMenuItem::getStructure() const
		{
			uint32_t codepage = ISerializable::getCodepage();
			json::JSONBuilder builder(codepage);

			builder.
				append("itemText"s, utility::to_string(text, codepage)).
				append("itemType"s, type);

			return builder;
		}

		IMenuItem::~IMenuItem()
		{
			DeleteMenu(parent, index, MF_BYPOSITION);
		}
	}
}
