#pragma once

#include "pch.h"
#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Components/IResizableComponent.h"
#include "Styles/Components/ListBoxes/ListBoxStyles.h"

namespace gui_framework
{
	/// @brief Base class for all list boxes
	class GUI_FRAMEWORK_API BaseListBox :
		public BaseComponent,
		public interfaces::IResizableComponent
	{
	protected:
		SIZE requiredSize;
		uint8_t columnsWidth;

	public:
		BaseListBox(const std::wstring& listBoxName, const utility::ComponentSettings& settings, const styles::ListBoxStyles& styles, BaseComponent* parent);

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

		/// @brief 
		/// @param subStringToFind 
		/// @return 
		/// @exception SelectListException 
		virtual LRESULT findSubstring(const std::wstring& subStringToFind) final;

		/// @brief 
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
		virtual LRESULT setCurrentSelection(LRESULT index) const;

		/// @brief 
		/// @return 
		/// @exception SelectListException 
		virtual LRESULT size() const final;

		/// @brief 
		virtual void clear() final;

		/// @brief 
		/// @param value 
		/// @param height 
		/// @return 
		/// @exception SelectListException 
		virtual LRESULT setItemsHeight(uint8_t height) final;

		/// @brief 
		/// @param width 
		/// @return 
		/// @exception SelectListException 
		virtual LRESULT setColumnsWidth(uint8_t width) final;

		/// @brief 
		/// @param value 
		/// @return 
		/// @exception SelectListException 
		virtual LRESULT getItemsHeight() const final;

		/// @brief 
		/// @return 
		/// @exception SelectListException 
		virtual uint8_t getColumnsWidth() const final;

		/// @brief 
		/// @param width 
		/// @param height 
		/// @exception SelectListException 
		virtual void resize(uint16_t width, uint16_t height);

		virtual ~BaseListBox() = default;
	};
}
