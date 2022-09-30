#pragma once

#include "BaseComposites/StandardComposites/BaseChildWindow.h"
#include "Interfaces/Components/IResizableComponent.h"

namespace gui_framework
{
	/// @brief Standard child window
	class GUI_FRAMEWORK_API ChildWindow :
		public BaseChildWindow,
		public interfaces::IResizableComponent	
	{
	public:
		ChildWindow(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, BaseComposite* parent, const std::string& windowFunctionName = "");

		/// @brief Not implemented
		/// @exception NotImplemented ChildWindow can't contain menus
		std::unique_ptr<Menu>& createMainMenu(const std::wstring& menuName) override;
		
		/// @brief Not implemented
		/// @exception NotImplemented ChildWindow can't contain menus
		Menu& addPopupMenu(const std::wstring& menuName) override;

		/// @brief Not implemented
		/// @exception NotImplemented ChildWindow can't contain menus
		void removePopupMenus(const std::wstring& menuName) override;

		size_t getHash() const override;

		~ChildWindow() = default;
	};
}
