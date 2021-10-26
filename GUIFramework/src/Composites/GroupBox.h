#pragma once

#include "headers.h"
#include "BaseComponents/StandardComponents/Buttons/BaseButton.h"
#include "BaseComposites/BaseComposite.h"

namespace gui_framework
{
	/// @brief Standard group box with radio buttons
	class GUI_FRAMEWORK_API GroupBox : public BaseComposite
	{
	private:
		class RadioButton : public BaseButton
		{
		public:
			RadioButton(const std::wstring& radioButtonName, const std::wstring& radioButtonText, const utility::ComponentSettings& settings, BaseComponent* parent, const std::function<void()>& onClick);

			RadioButton(const std::wstring& radioButtonName, const std::wstring& radioButtonText, const utility::ComponentSettings& settings, BaseComponent* parent, const std::string& functionName, const std::string& moduleName);

			size_t getHash() const override;

			~RadioButton() = default;
		};

	public:
		struct GUI_FRAMEWORK_API radioButtonData
		{
			std::wstring radioButtonName;
			std::wstring radioButtonText;
			int x;
			int y;
			uint16_t width;
			uint16_t height;
			std::function<void()> onClick;
			std::string functionName;
			std::string moduleName;

			radioButtonData();

			radioButtonData(const std::wstring& radioButtonName, const std::wstring& radioButtonText, const utility::ComponentSettings& settings, const std::function<void()>& onClick);

			/// @brief 
			/// @param radioButtonName 
			/// @param radioButtonText 
			/// @param settings 
			/// @param functionName 
			/// @param moduleName 
			/// @exception CantFindFunctionFromModuleException 
			radioButtonData(const std::wstring& radioButtonName, const std::wstring& radioButtonText, const utility::ComponentSettings& settings, const std::string& functionName, const std::string& moduleName);

			~radioButtonData() = default;
		};

	public:
		/// @brief 
		/// @param groupBoxClassName 
		/// @param groupBoxName 
		/// @param x 
		/// @param y 
		/// @param width 
		/// @param height 
		/// @param parent 
		/// @param groupBoxFunctionName Value that you pass in CREATE_DEFAULT_WINDOW_FUNCTION macro
		GroupBox(const std::wstring& groupBoxClassName, const std::wstring& groupBoxName, const utility::ComponentSettings& settings, BaseComponent* parent, const std::string& groupBoxFunctionName);

		void addRadioButton(const radioButtonData& data);

		/// @brief Not implemented
		/// @exception NotImplemented GroupBox can't contain menus
		std::unique_ptr<Menu>& createMainMenu(const std::wstring& menuName) override;

		/// @brief Not implemented
		/// @exception NotImplemented GroupBox can't contain menus
		Menu& addPopupMenu(const std::wstring& menuName) override;

		/// @brief Not implemented
		/// @exception NotImplemented GroupBox can't contain menus
		void removePopupMenus(const std::wstring& menuName) override;

		size_t getHash() const override;

		~GroupBox() = default;
	};
}
