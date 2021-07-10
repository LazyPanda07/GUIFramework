#pragma once

#include "BaseComponents/StandardComponents/BaseButton.h"

namespace gui_framework
{
	/// @brief Standard group box with radio buttons
	class GUI_FRAMEWORK_API GroupBox : public BaseButton
	{
	private:
		class RadioButton : public BaseButton
		{
		public:
			RadioButton(const std::wstring& radioButtonName, const std::wstring& radioButtonText, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, const std::function<LRESULT(WPARAM, LPARAM)>& onClick);

			~RadioButton() = default;
		};

	private:
		std::vector<std::unique_ptr<RadioButton>> buttons;

	public:
		GroupBox(const std::wstring& groupBoxName, const std::wstring& groupBoxText, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent);

		virtual void addRadioButton(const std::wstring& radioButtonName, const std::wstring& radioButtonText, int x, int y, uint16_t width, uint16_t height, const std::function<LRESULT(WPARAM, LPARAM)>& onClick) final;

		virtual ~GroupBox() = default;
	};
}
