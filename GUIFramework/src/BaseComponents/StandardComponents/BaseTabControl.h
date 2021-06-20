#pragma once

#include "BaseComponents/BaseComponent.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API BaseTabControl :
		virtual public BaseComponent
	{
	protected:
		HIMAGELIST imageList;
		std::unordered_map<std::wstring, uint16_t> images;
		uint16_t iconWidth;
		uint16_t iconHeight;

	public:
		BaseTabControl(const std::wstring& tabControlName, const utility::ComponentSettings& settings, uint16_t iconsWidth, uint16_t iconsHeight, BaseComponent* parent);

		virtual LRESULT appendText(const std::wstring& text) final;

		virtual LRESULT insertText(size_t index, const std::wstring& text) final;

		/// @brief 
		/// @param pathToImage 
		/// @return
		/// @exception gui_framework::exceptions::FileDoesNotExist
		virtual LRESULT appendImage(const std::filesystem::path& pathToImage) final;

		/// @brief 
		/// @param pathToImage 
		/// @param index 
		/// @return 
		/// @exception gui_framework::exceptions::FileDoesNotExist
		virtual LRESULT insertImage(size_t index, const std::filesystem::path& pathToImage) final;

		/// @brief 
		/// @param text 
		/// @param pathToImage 
		/// @return
		/// @exception gui_framework::exceptions::FileDoesNotExist 
		virtual LRESULT appendTextAndImage(const std::wstring& text, const std::filesystem::path& pathToImage) final;

		/// @brief 
		/// @param text 
		/// @param pathToImage 
		/// @param index 
		/// @return 
		/// @exception gui_framework::exceptions::FileDoesNotExist 
		virtual LRESULT insertTextAndImage(size_t index, const std::wstring& text, const std::filesystem::path& pathToImage) final;

		/// @brief 
		/// @param index 
		/// @param text 
		/// @param pathToImage 
		/// @return 
		/// @exception gui_framework::exceptions::FileDoesNotExist 
		virtual bool setItem(size_t index, const std::wstring& text = L"", const std::filesystem::path& pathToImage = L"") final;

		virtual TCITEMW getItem(size_t index) final;

		virtual bool removeTab(size_t index) final;

		virtual bool clear() final;

		virtual size_t size() const final;

		virtual ~BaseTabControl();
	};
}
