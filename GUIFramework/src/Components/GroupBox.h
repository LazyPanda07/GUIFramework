#pragma once

#include "BaseComponents/StandardComponents/BaseButton.h"
#include "BaseComposites/BaseComposite.h"

#pragma warning(push)
#pragma warning(disable: 4250)

namespace gui_framework
{
	/// @brief Standard group box with radio buttons
	class GUI_FRAMEWORK_API GroupBox : public BaseComposite
	{
	private:
		class RadioButton : public BaseButton
		{
		public:
			RadioButton(const std::wstring& radioButtonName, const std::wstring& radioButtonText, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, const std::function<void()>& onClick);

			~RadioButton() = default;
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
		GroupBox(const std::wstring& groupBoxClassName, const std::wstring& groupBoxName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, const std::string& groupBoxFunctionName);

		virtual void addRadioButton(const std::wstring& radioButtonName, const std::wstring& radioButtonText, int x, int y, uint16_t width, uint16_t height, const std::function<void()>& onClick) final;

		~GroupBox() = default;
	};
}

#pragma warning(pop)
