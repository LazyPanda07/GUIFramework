#pragma once

#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Components/IResizableComponent.h"

namespace gui_framework
{
	/// @brief Base class for all combo boxes
	class GUI_FRAMEWORK_API BaseComboBox :
		virtual public BaseComponent,
		public interfaces::IResizableComponent
	{
	protected:
		SIZE requiredSize;

	public:
		enum class itemHeightEnum
		{
			forAllItems,
			selectionFieldItem
		};

	public:
		BaseComboBox(const std::wstring& comboBoxName, const utility::ComponentSettings& settings, BaseComponent* parent);

		/// @brief 
		/// @param value 
		/// @return
		/// @exception gui_framework::exceptions::SelectListException 
		virtual LRESULT addValue(const std::wstring& value) final;

		/// @brief 
		/// @param index 
		/// @return 
		/// @exception gui_framework::exceptions::SelectListException 
		virtual LRESULT removeValue(size_t index) final;

		/// @brief 
		/// @param value 
		/// @param index 
		/// @return 
		/// @exception gui_framework::exceptions::SelectListException 
		virtual LRESULT insertValue(const std::wstring& value, LRESULT index);

		/// @brief 
		/// @param newValue 
		/// @param index 
		/// @return 
		/// @exception gui_framework::exceptions::SelectListException 
		virtual LRESULT changeValue(const std::wstring& newValue, LRESULT index);

		/// @brief Find not case sensitive substring
		/// @param subStringToFind 
		/// @return 
		/// @exception gui_framework::exceptions::SelectListException 
		virtual LRESULT findSubstring(const std::wstring& substringToFind) final;

		/// @brief Find not case sensitive string
		/// @param stringToFind 
		/// @return 
		/// @exception gui_framework::exceptions::SelectListException 
		virtual LRESULT findString(const std::wstring& stringToFind) final;

		/// @brief 
		/// @param index 
		/// @return 
		/// @exception gui_framework::exceptions::SelectListException 
		virtual std::wstring getValue(size_t index) const final;
		
		/// @brief 
		/// @return 
		/// @exception gui_framework::exceptions::SelectListException 
		virtual LRESULT getCurrentSelectionIndex() const final;

		/// @brief 
		/// @param index 
		/// @return 
		/// @exception gui_framework::exceptions::SelectListException 
		virtual LRESULT setCurrentSelection(LRESULT index) const final;

		/// @brief 
		/// @return 
		/// @exception gui_framework::exceptions::SelectListException 
		virtual LRESULT size() const final;

		/// @brief 
		virtual void clear() final;

		/// @brief 
		/// @param isSorting 
		virtual void setSortingMode(bool isSorting) final;

		/// @brief 
		/// @param value 
		/// @param height 
		/// @return 
		/// @exception gui_framework::exceptions::SelectListException 
		virtual LRESULT setItemHeight(itemHeightEnum value, uint16_t height) final;

		/// @brief 
		/// @param width 
		/// @return 
		/// @exception gui_framework::exceptions::SelectListException 
		virtual LRESULT setDroppedWidth(uint16_t width) final;

		/// @brief 
		/// @param value 
		/// @return 
		/// @exception gui_framework::exceptions::SelectListException 
		virtual LRESULT getItemHeight(itemHeightEnum value) const final;

		/// @brief 
		/// @return 
		/// @exception gui_framework::exceptions::SelectListException 
		virtual LRESULT getDroppedWidth() const final;

		/// @brief 
		/// @param width 
		/// @param height 
		/// @exception gui_framework::exceptions::SelectListException 
		virtual void resize(uint16_t width, uint16_t height) override;

		virtual ~BaseComboBox() = default;
	};
}
