#pragma once

#include "BaseComponents/BaseComponent.h"
#include "Holders/LoadableHolders/ImagesHolder.h"

namespace gui_framework
{
	/// @brief Base class for all tab controls
	class GUI_FRAMEWORK_API BaseTabControl : public BaseComponent
	{
	public:
		struct GUI_FRAMEWORK_API tabData
		{
			std::wstring text;
			std::filesystem::path pathToImage;
			std::function<void()> callback;
			std::string functionName;
			std::string moduleName;

			tabData() = default;

			tabData(const std::wstring& text, const std::filesystem::path& pathToImage, const std::function<void()>& callback);

			tabData(const std::wstring& text, const std::filesystem::path& pathToImage, const std::string& functionName, const std::string& moduleName);

			tabData(const tabData&) = default;

			tabData(tabData&&) noexcept = default;

			tabData& operator = (const tabData&) = default;

			tabData& operator = (tabData&&) noexcept = default;

			~tabData() = default;
		};

	protected:
		utility::ImagesHolder images;
		std::vector<std::function<void()>> callbacks;
		std::vector<tabData> tabs;

	protected:
		virtual LRESULT windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) override;

	public:
		BaseTabControl(const std::wstring& tabControlName, const utility::ComponentSettings& settings, uint16_t imagesWidth, uint16_t imagesHeight, BaseComposite* parent);

		virtual LRESULT appendText(const std::wstring& text, const std::function<void()>& onClick) final;

		/// @brief 
		/// @param text 
		/// @param functionName 
		/// @param moduleName 
		/// @return
		/// @exception CantFindFunctionFromModuleException 
		/// @exception std::out_of_range Can't find moduleName in loaded modules
		virtual LRESULT appendText(const std::wstring& text, const std::string& functionName, const std::string& moduleName) final;

		virtual LRESULT insertText(size_t index, const std::wstring& text, const std::function<void()>& onClick) final;

		/// @brief 
		/// @param index 
		/// @param text 
		/// @param functionName 
		/// @param moduleName 
		/// @return
		/// @exception CantFindFunctionFromModuleException 
		/// @exception std::out_of_range Can't find moduleName in loaded modules 
		virtual LRESULT insertText(size_t index, const std::wstring& text, const std::string& functionName, const std::string& moduleName) final;

		/// @brief 
		/// @param pathToImage 
		/// @return
		/// @exception FileDoesNotExist
		virtual LRESULT appendImage(const std::filesystem::path& pathToImage, const std::function<void()>& onClick) final;

		/// @brief 
		/// @param pathToImage 
		/// @return
		/// @exception FileDoesNotExist
		/// @exception CantFindFunctionFromModuleException 
		/// @exception std::out_of_range Can't find moduleName in loaded modules
		virtual LRESULT appendImage(const std::filesystem::path& pathToImage, const std::string& functionName, const std::string& moduleName) final;

		/// @brief 
		/// @param pathToImage 
		/// @param index 
		/// @return 
		/// @exception FileDoesNotExist
		virtual LRESULT insertImage(size_t index, const std::filesystem::path& pathToImage, const std::function<void()>& onClick) final;

		/// @brief 
		/// @param pathToImage 
		/// @param index 
		/// @return 
		/// @exception FileDoesNotExist
		/// @exception CantFindFunctionFromModuleException 
		/// @exception std::out_of_range Can't find moduleName in loaded modules
		virtual LRESULT insertImage(size_t index, const std::filesystem::path& pathToImage, const std::string& functionName, const std::string& moduleName) final;

		/// @brief 
		/// @param text 
		/// @param pathToImage 
		/// @return
		/// @exception FileDoesNotExist 
		virtual LRESULT appendTextAndImage(const std::wstring& text, const std::filesystem::path& pathToImage, const std::function<void()>& onClick) final;

		/// @brief 
		/// @param text 
		/// @param pathToImage 
		/// @return
		/// @exception FileDoesNotExist 
		/// @exception CantFindFunctionFromModuleException 
		/// @exception std::out_of_range Can't find moduleName in loaded modules
		virtual LRESULT appendTextAndImage(const std::wstring& text, const std::filesystem::path& pathToImage, const std::string& functionName, const std::string& moduleName) final;

		/// @brief 
		/// @param text 
		/// @param pathToImage 
		/// @param index 
		/// @return 
		/// @exception FileDoesNotExist 
		virtual LRESULT insertTextAndImage(size_t index, const std::wstring& text, const std::filesystem::path& pathToImage, const std::function<void()>& onClick) final;

		/// @brief 
		/// @param text 
		/// @param pathToImage 
		/// @param index 
		/// @return 
		/// @exception FileDoesNotExist 
		/// @exception CantFindFunctionFromModuleException 
		/// @exception std::out_of_range Can't find moduleName in loaded modules
		virtual LRESULT insertTextAndImage(size_t index, const std::wstring& text, const std::filesystem::path& pathToImage, const std::string& functionName, const std::string& moduleName) final;

		virtual bool removeTab(size_t index) final;

		virtual bool clear() final;

		virtual size_t size() const final;

		/// @brief 
		/// @param index 
		/// @param text 
		/// @param pathToImage 
		/// @return 
		/// @exception FileDoesNotExist 
		virtual bool setItem(size_t index, const std::function<void()>& callback, const std::wstring& text = L"", const std::filesystem::path& pathToImage = L"") final;

		/// @brief 
		/// @param index 
		/// @param functionName 
		/// @param moduleName 
		/// @param text 
		/// @param pathToImage 
		/// @return 
		/// @exception FileDoesNotExist 
		/// @exception CantFindFunctionFromModuleException 
		/// @exception std::out_of_range Can't find moduleName in loaded modules
		virtual bool setItem(size_t index, const std::string& functionName, const std::string& moduleName, const std::wstring& text = L"", const std::filesystem::path& pathToImage = L"") final;

		/// @brief 
		/// @return Returns the index of the previously selected tab if successful, or -1 otherwise 
		virtual LRESULT setSelection(size_t index) final;

		/// @brief 
		/// @param index 
		/// @return
		/// @exception std::out_of_range 
		virtual const tabData& getItem(size_t index) const final;

		virtual LRESULT getSelectedTab() const final;

		virtual uint16_t getImagesWidth() const final;

		virtual uint16_t getImagesHeight() const final;

		/// @brief Not implemented
		/// @param red 
		/// @param green 
		/// @param blue 
		/// @exception NotImplemented Background color does not affects at tab control
		virtual void setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue) final override;

		/// @brief Not implemented
		/// @param red 
		/// @param green 
		/// @param blue 
		/// @exception NotImplemented Text color does not affects at tab control
		virtual void setTextColor(uint8_t red, uint8_t green, uint8_t blue) final override;

		/// @brief Used as key in creators
		/// @return typeid().hash_code()
		virtual size_t getHash() const override = 0;

		virtual json::JSONBuilder getStructure() const override;

		virtual ~BaseTabControl() = default;
	};
}
