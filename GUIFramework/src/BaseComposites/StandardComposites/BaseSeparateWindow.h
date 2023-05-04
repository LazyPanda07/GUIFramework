#pragma once

#include "BaseWindow.h"
#include "Interfaces/Components/ICloseable.h"

namespace gui_framework
{
	/// @brief Base class for separate windows
	class GUI_FRAMEWORK_API BaseSeparateWindow :
		public BaseWindow,
		public interfaces::ICloseable
	{
	protected:
		HICON largeIcon;
		HICON smallIcon;
		std::filesystem::path pathToSmallIcon;
		std::filesystem::path pathToLargeIcon;

	public:
		/// @brief 
		/// @param moduleName Name of loaded resource module with icons
		/// @param smallIconResource Integer value from auto generated Visual Studio resources
		/// @param largeIconResource Integer value from auto generated Visual Studio resources
		BaseSeparateWindow(const std::wstring& className, const std::wstring& titleName, const utility::ComponentSettings& settings, const std::string& windowFunctionName, bool maximize = false, bool minimize = false, const std::string& moduleName = "", uint16_t smallIconResource = NULL, uint16_t largeIconResource = NULL);

		/// @brief Enable resize button and window resizing
		void enableResize();

		/// @brief Disable resize button and window resizing
		void disableResize();

		/// @brief Set large icon(32x32) for specific window
		/// @param pathToLargeIcon 
		/// @exception FileDoesNotExist
		void setLargeIcon(const std::filesystem::path& pathToLargeIcon);

		/// @brief Set small icon(16x16) for specific window
		/// @param pathToSmallIcon 
		/// @exception FileDoesNotExist
		void setSmallIcon(const std::filesystem::path& pathToSmallIcon);

		/// @brief Used as key in creators
		/// @return typeid().hash_code()
		virtual size_t getHash() const override = 0;

		virtual json::JSONBuilder getStructure() const override;

		virtual ~BaseSeparateWindow();
	};
}
