#pragma once

#include "BaseListBox.h"

namespace gui_framework
{
	class BaseMultipleSelectListBox : public BaseListBox
	{
	public:
		BaseMultipleSelectListBox(const std::wstring& listBoxName, const utility::ComponentSettings& settings, BaseComponent* parent);

		virtual LRESULT getCurrentSelections() const final;

		virtual std::vector<std::wstring> getSelectedItems() const final;

		virtual void selectMultipleItems(WPARAM firstItemIndex, LPARAM lastItemIndex) const final;

		virtual LRESULT setCurrentSelection(LRESULT index) const final override;

		virtual ~BaseMultipleSelectListBox() = default;
	};
}