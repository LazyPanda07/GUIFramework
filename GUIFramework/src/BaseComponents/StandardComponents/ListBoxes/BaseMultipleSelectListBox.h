#pragma once

#include "core.h"
#include "BaseListBox.h"

namespace gui_framework
{
	/// @brief Base class for all multiple select list boxes
	class GUI_FRAMEWORK_API BaseMultipleSelectListBox : public BaseListBox
	{
	public:
		BaseMultipleSelectListBox(const std::wstring& listBoxName, const utility::ComponentSettings& settings, BaseComposite* parent);

		LRESULT getCurrentSelections() const ;

		std::vector<std::wstring> getSelectedItems() const;

		void selectMultipleItems(WPARAM firstItemIndex, LPARAM lastItemIndex) const;

		virtual LRESULT setCurrentSelection(LRESULT index) const final override;

		/// @brief Used as key in creators
		/// @return typeid().hash_code()
		virtual size_t getHash() const override = 0;

		virtual json::JSONBuilder getStructure() const override;

		virtual ~BaseMultipleSelectListBox() = default;
	};
}
