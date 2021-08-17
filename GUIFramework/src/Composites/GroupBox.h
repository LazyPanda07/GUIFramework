#pragma once

#include "pch.h"
#include "BaseComponents/StandardComponents/BaseButton.h"
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

			~RadioButton() = default;
		};

	public:
		struct radioButtonData
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

			radioButtonData(const std::wstring& radioButtonName, const std::wstring& radioButtonText, const utility::ComponentSettings& settings, const std::string& functionName, const std::string& moduleName);

			~radioButtonData() = default;
		};

	protected:
		virtual const std::string& getCreationType() const override;

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

		~GroupBox() = default;
	};
}
