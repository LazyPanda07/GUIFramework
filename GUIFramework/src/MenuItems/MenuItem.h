#pragma once

#include "headers.h"
#include "Menu/MenuItems/BaseMenuItem.h"

namespace gui_framework
{
	/// @brief Standard menu item
	class GUI_FRAMEWORK_API MenuItem : public BaseMenuItem
	{
	private:
		std::function<void()> onClick;
		std::string functionName;
		std::string moduleName;

	public:
		MenuItem(const std::wstring& text, const std::function<void()>& onClick);

		/// @brief 
		/// @param text 
		/// @param functionName 
		/// @param moduleName 
		/// @exception CantFindFunctionFromModuleException 
		MenuItem(const std::wstring& text, const std::string& functionName, const std::string& moduleName);

		void processMessage() override;

		json::JSONBuilder getStructure() const override;

		~MenuItem() = default;
	};
}
