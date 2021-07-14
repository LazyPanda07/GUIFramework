#pragma once

#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Components/IResizableComponent.h"
#include "Styles/Components/ComboBoxes/ComboBoxStyles.h"

namespace gui_framework
{
	/// @brief Base class for all combo boxes
	class GUI_FRAMEWORK_API BaseComboBox :
		public BaseComponent,
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
		BaseComboBox(const std::wstring& comboBoxName, const utility::ComponentSettings& settings, const styles::ComboBoxStyles& styles, BaseComponent* parent);

		/// @brief 
		/// @param value 
		/// @return
		/// @exception SelectListException 
		virtual LRESULT addValue(const std::wstring& value) final;

		/// @brief 
		/// @param index 
		/// @return 
		/// @exception SelectListException 
		virtual LRESULT removeValue(size_t index) final;

		/// @brief 
		/// @param value 
		/// @param index 
		/// @return 
		/// @exception SelectListException 
		virtual LRESULT insertValue(const std::wstring& value, LRESULT index);

		/// @brief 
		/// @param newValue 
		/// @param index 
		/// @return 
		/// @exception SelectListException 
		virtual LRESULT changeValue(const std::wstring& newValue, LRESULT index);

		/// @brief Find not case sensitive substring
		/// @param subStringToFind 
		/// @return 
		/// @exception SelectListException 
		virtual LRESULT findSubstring(const std::wstring& substringToFind) final;

		/// @brief Find not case sensitive string
		/// @param stringToFind 
		/// @return 
		/// @exception SelectListException 
		virtual LRESULT findString(const std::wstring& stringToFind) final;

		/// @brief 
		/// @param index 
		/// @return 
		/// @exception SelectListException 
		virtual std::wstring getValue(size_t index) const final;
		
		/// @brief 
		/// @return 
		/// @exception SelectListException 
		virtual LRESULT getCurrentSelectionIndex() const final;

		/// @brief 
		/// @param index 
		/// @return 
		/// @exception SelectListException 
		virtual LRESULT setCurrentSelection(LRESULT index) const final;

		/// @brief 
		/// @return 
		/// @exception SelectListException 
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
		/// @exception SelectListException 
		virtual LRESULT setItemHeight(itemHeightEnum value, uint16_t height) final;

		/// @brief 
		/// @param width 
		/// @return 
		/// @exception SelectListException 
		virtual LRESULT setDroppedWidth(uint16_t width) final;

		/// @brief 
		/// @param value 
		/// @return 
		/// @exception SelectListException 
		virtual LRESULT getItemHeight(itemHeightEnum value) const final;

		/// @brief 
		/// @return 
		/// @exception SelectListException 
		virtual LRESULT getDroppedWidth() const final;

		/// @brief 
		/// @param width 
		/// @param height 
		/// @exception SelectListException 
		virtual void resize(uint16_t width, uint16_t height) override;

		/// @brief Not implemented
		/// @param red 
		/// @param green 
		/// @param blue 
		/// @exception NotImplemented Background color does not affects at combo boxes
		virtual void setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue) final override;

		/// @brief Not implemented
		/// @param red 
		/// @param green 
		/// @param blue 
		/// @exception NotImplemented Text color does not affects at combo boxes
		virtual void setTextColor(uint8_t red, uint8_t green, uint8_t blue) final override;

		virtual ~BaseComboBox() = default;
	};
}
