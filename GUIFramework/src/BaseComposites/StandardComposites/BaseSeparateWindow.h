#pragma once

#include "headers.h"
#include "BaseWindow.h"

namespace gui_framework
{
	/// @brief Base class for separate windows
	class GUI_FRAMEWORK_API BaseSeparateWindow : public BaseWindow
	{
	protected:
		HICON largeIcon;
		HICON smallIcon;
		std::filesystem::path pathToSmallIcon;
		std::filesystem::path pathToLargeIcon;
		std::function<bool()> onClose;
		std::string onCloseFunctionName;
		std::string onCloseFunctionModuleName;

	public:
		/// @brief 
		/// @param moduleName Name of loaded resource module with icons
		/// @param smallIconResource Integer value from auto generated Visual Studio resources
		/// @param largeIconResource Integer value from auto generated Visual Studio resources
		BaseSeparateWindow(const std::wstring& className, const std::wstring& titleName, const utility::ComponentSettings& settings, const std::string& windowFunctionName, bool maximize = false, bool minimize = false, const std::string& moduleName = "", uint16_t smallIconResource = NULL, uint16_t largeIconResource = NULL);

		/// @brief Set large icon(32x32) for specific window
		/// @param pathToLargeIcon 
		/// @exception FileDoesNotExist
		virtual void setLargeIcon(const std::filesystem::path& pathToLargeIcon) final;

		/// @brief Set small icon(16x16) for specific window
		/// @param pathToSmallIcon 
		/// @exception FileDoesNotExist
		virtual void setSmallIcon(const std::filesystem::path& pathToSmallIcon) final;

		virtual void setOnClose(const std::function<bool()>& onClose) final;

		/// @brief Load function from module. Can be seriazlied
		/// @param onCloseFunctionName 
		/// @param onCloseFunctionModuleName 
		/// @exception CantFindFunctionFromModuleException 
		/// @exception std::out_of_range Can't find moduleName in loaded modules
		virtual void setOnClose(const std::string& onCloseFunctionName, const std::string& onCloseFunctionModuleName) final;

		virtual const std::function<bool()>& getOnClose() const final;

		/// @brief Used as key in creators
		/// @return typeid().hash_code()
		virtual size_t getHash() const override = 0;

		virtual json::JSONBuilder getStructure() const override;

		virtual ~BaseSeparateWindow();
	};
}
