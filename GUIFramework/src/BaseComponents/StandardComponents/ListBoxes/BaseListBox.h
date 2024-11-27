#pragma once

#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Components/IResizableComponent.h"
#include "Styles/Components/ListBoxes/ListBoxStyles.h"
#include "Interfaces/Localization/IMultipleTextLocalized.h"

namespace gui_framework
{
	/// @brief Base class for all list boxes
	class GUI_FRAMEWORK_API BaseListBox :
		public interfaces::IMultipleTextLocalized,
		public BaseComponent,
		public interfaces::IResizableComponent
	{
	protected:
		SIZE requiredSize;
		uint8_t columnsWidth;

	protected:
		virtual void updateLocalization(size_t index, std::wstring_view localizedText) override;

	public:
		BaseListBox(std::wstring_view listBoxName, const utility::ComponentSettings& settings, const styles::ListBoxStyles& styles, BaseComposite* parent);

		/// @brief 
		/// @param value 
		/// @return
		/// @exception SelectListException 
		LRESULT addValue(std::wstring_view value);

		/// @brief 
		/// @param localizationKey 
		/// @return
		/// @exception SelectListException 
		/// @exception std::runtime_error
		LRESULT addValue(std::string_view localizationKey);

		/// @brief 
		/// @param index 
		/// @return 
		/// @exception SelectListException 
		LRESULT removeValue(size_t index);

		/// @brief 
		/// @param value 
		/// @param index 
		/// @return 
		/// @exception SelectListException 
		virtual LRESULT insertValue(std::wstring_view value, LRESULT index);

		/// @brief 
		/// @param localizationKey 
		/// @param index 
		/// @return 
		/// @exception SelectListException 
		LRESULT insertValue(std::string_view localizationKey, LRESULT index);

		/// @brief 
		/// @param newValue 
		/// @param index 
		/// @return 
		/// @exception SelectListException 
		virtual LRESULT changeValue(std::wstring_view newValue, LRESULT index);

		/// @brief 
		/// @param localizationKey 
		/// @param index 
		/// @return 
		/// @exception SelectListException 
		LRESULT changeValue(std::string_view localizationKey, LRESULT index);

		/// @brief 
		/// @param subStringToFind 
		/// @return 
		/// @exception SelectListException 
		LRESULT findSubstring(std::wstring_view subStringToFind);

		/// @brief 
		/// @param stringToFind 
		/// @return 
		/// @exception SelectListException 
		LRESULT findString(std::wstring_view stringToFind);

		/// @brief 
		/// @param index 
		/// @return 
		/// @exception SelectListException 
		std::wstring getValue(size_t index) const;

		/// @brief 
		/// @return 
		/// @exception SelectListException 
		LRESULT getCurrentSelectionIndex() const;

		/// @brief 
		/// @param index 
		/// @return 
		/// @exception SelectListException 
		virtual LRESULT setCurrentSelection(LRESULT index) const;

		/// @brief 
		/// @return 
		/// @exception SelectListException 
		LRESULT size() const;

		/// @brief 
		void clear();

		/// @brief 
		/// @param value 
		/// @param height 
		/// @return 
		/// @exception SelectListException 
		LRESULT setItemsHeight(uint8_t height);

		/// @brief 
		/// @param width 
		/// @return 
		/// @exception SelectListException 
		LRESULT setColumnsWidth(uint8_t width);

		/// @brief 
		/// @param value 
		/// @return 
		/// @exception SelectListException 
		LRESULT getItemsHeight() const;

		/// @brief 
		/// @return 
		/// @exception SelectListException 
		uint8_t getColumnsWidth() const;

		/// @brief 
		/// @param width 
		/// @param height 
		/// @exception SelectListException 
		virtual void resize(uint16_t width, uint16_t height) override;

		/// @brief Used as key in creators
		/// @return typeid().hash_code()
		virtual size_t getHash() const override = 0;

		virtual json::JSONBuilder getStructure() const override;

		virtual ~BaseListBox() = default;
	};
}
