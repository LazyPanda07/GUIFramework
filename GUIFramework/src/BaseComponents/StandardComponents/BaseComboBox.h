#pragma once

/// @file BaseComboBox.h

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
		std::function<void(BaseComboBox&)> onSelectionChange;
		std::string functionName;
		std::string moduleName;

	protected:
		virtual LRESULT windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) final override;

	public:
		/// @brief Load function from module
		/// @param onSelectionChange Output parameter for function load
		/// @param functionName Name of function in module
		/// @param moduleName Name of module in JSON array modules in gui_framework.json
		/// @exception CantFindFunctionFromModuleException 
		static void loadOnSelectionChangeFromModule(std::function<void(BaseComboBox&)>& onSelectionChange, const std::string& functionName, const std::string& moduleName);

	public:
		enum class itemHeightEnum
		{
			forAllItems,
			selectionFieldItem
		};

	public:
		BaseComboBox(const std::wstring& comboBoxName, const utility::ComponentSettings& settings, const styles::ComboBoxStyles& styles, BaseComposite* parent);

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

		/// @brief Set callback function with on selection change event
		/// @param onSelectionChange callback with reference to current BaseCombobox
		virtual void setOnSelectionChange(const std::function<void(BaseComboBox&)>& onSelectionChange) final;

		/// @brief Set serializable callback function with on selection change event
		/// @param functionName Name of function with comboBoxCallbackSignature signature
		/// @param moduleName 
		/// @exception CantFindFunctionFromModuleException 
		/// @exception std::out_of_range Can't find moduleName in loaded modules
		virtual void setOnSelectionChange(const std::string& functionName, const std::string& moduleName) final;

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

		/// @brief Used as key in creators
		/// @return typeid().hash_code()
		virtual size_t getHash() const override = 0;

		virtual json::JSONBuilder getStructure() const override;

		virtual ~BaseComboBox() = default;
	};

	/// @brief Used in notification events in combo box
	using comboBoxCallbackSignature = void(*)(BaseComboBox&);
}
