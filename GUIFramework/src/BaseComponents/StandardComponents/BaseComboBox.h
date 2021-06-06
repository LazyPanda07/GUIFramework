#pragma once

#include "BaseComponents/BaseComponent.h"

namespace gui_framework
{
	class BaseComboBox : virtual public BaseComponent
	{
	public:
		BaseComboBox(const std::wstring& comboBoxName, const utility::ComponentSettings& settings, BaseComponent* parent);

		virtual ~BaseComboBox() = default;
	};
}
