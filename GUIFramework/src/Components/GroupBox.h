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
		GroupBox(const std::wstring& groupBoxClassName, const std::wstring& groupBoxName, const std::wstring& groupBoxText, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent);

		virtual void addRadioButton(const std::wstring& radioButtonName, const std::wstring& radioButtonText, int x, int y, uint16_t width, uint16_t height, const std::function<void()>& onClick) final;

		virtual ~GroupBox() = default;
	};
}

#pragma warning(pop)
