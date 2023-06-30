#pragma once

#include "Core.h"
#include "Utility/Utility.h"
#include "Utility/ComponentSettings.h"
#include "Holders/LoadableHolders/IconsHolder.h"
#include "Interfaces/Styles/IStyles.h"
#include "Interfaces/Utility/ISerializable.h"
#include "Interfaces/Localization/ITextLocalized.h"

namespace gui_framework
{
	class BaseComposite;

	/// @brief Base class for all windows, controls, etc.
	class GUI_FRAMEWORK_API BaseComponent : public interfaces::ISerializable
	{
	public:
		/// @brief Add task to thread pool
		/// @param callable Function to call async
		/// @param callback Function to call after callable invokes
		static void runFunctionAsync(const std::function<void()>& callable, const std::function<void()>& callback = nullptr) noexcept;

		/// @brief Add task to thread pool
		/// @param callable Function to call async
		/// @param callback Function to call after callable invokes
		static void runFunctionAsync(std::function<void()>&& callable, const std::function<void()>& callback = nullptr) noexcept;

	protected:
		BaseComposite* parent;
		const std::wstring className;
		const std::wstring windowName;
		HWND handle;
		uint16_t desiredWidth;
		uint16_t desiredHeight;
		int desiredX;
		int desiredY;
		uint32_t id;
		COLORREF backgroundColor;
		COLORREF textColor;
		smartPointerType<interfaces::IStyles> styles;

	protected:
		virtual LRESULT preWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed);

		virtual LRESULT windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed);

	protected:
		/// @brief Override for custom localization
		/// 
		/// Your interface must be implemented before BaseComponent subclass inheritance
		/// @param localized Non nullptr base localization class pointer
		virtual void setLocalizationKeys(interfaces::ITextLocalized* localized, const std::vector<std::string>& localizationKeys);

	public:
		/// @brief 
		/// @param windowFunctionName Value that you pass in CREATE_DEFAULT_WINDOW_FUNCTION macro
		/// @param moduleName Name of loaded resource module with icons
		/// @param smallIconResource Integer value from auto generated Visual Studio resources
		/// @param largeIconResource Integer value from auto generated Visual Studio resources
		BaseComponent(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, const interfaces::IStyles& styles, BaseComposite* parent = nullptr, const std::string& windowFunctionName = "", const std::string& moduleName = "", uint16_t smallIconResource = NULL, uint16_t largeIconResource = NULL);

		LRESULT handleMessages(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed);

		bool destroyComponent();

		bool asyncDestroyComponent();

		/// @brief If the window was previously disabled, the return value is true.
		/// @return 
		bool enable();

		/// @brief If the window was not previously disabled, the return value is false.
		/// @return 
		bool disable();

		/**
		 * @brief SendMessage WinAPI wrapper
		 * @param message 
		 * @param wparam 
		 * @param lparam 
		 * @return 
		*/
		LRESULT sendRawMessage(UINT message, WPARAM wparam, LPARAM lparam);

		void setDesiredWidth(uint16_t desiredWidth);

		void setDesiredHeight(uint16_t desiredHeight);

		void setDesiredX(int desiredX);

		void setDesiredY(int desiredY);

		virtual void setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue);

		virtual void setTextColor(uint8_t red, uint8_t green, uint8_t blue);

		BaseComponent* getParent() const;

		HWND getHandle() const;

		const std::wstring& getWindowName() const;

		const std::wstring& getClassName() const;

		uint16_t getDesiredWidth() const;

		uint16_t getDesiredHeight() const;

		uint16_t getActualWidth() const;

		uint16_t getActualHeight() const;

		RECT getActualCoordinates() const;

		int getDesiredX() const;

		int getDesiredY() const;

		/// @brief 
		/// @return Components returns id, composites returns 0 
		uint32_t getId() const;

		COLORREF getBackgroundColor() const;

		COLORREF getTextColor() const;

		const smartPointerType<interfaces::IStyles>& getStyles() const;

		/// @brief Used as key in creators
		/// @return typeid().hash_code()
		virtual size_t getHash() const = 0;

		virtual json::JSONBuilder getStructure() const override;

		virtual ~BaseComponent();

		friend class BaseComposite;
	};
}
