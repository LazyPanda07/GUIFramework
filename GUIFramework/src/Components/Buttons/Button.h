#pragma once

#include "headers.h"
#include "BaseComponents/StandardComponents/Buttons/BaseButton.h"
#include "Interfaces/Components/IResizableComponent.h"

namespace gui_framework
{
	/// @brief Standard button
	class GUI_FRAMEWORK_API Button :
		public BaseButton,
		public interfaces::IResizableComponent
	{
	public:
		Button(const std::wstring& buttonName, const std::wstring& buttonText, int x, int y, BaseComponent* parent, const std::function<void()>& onClick = nullptr, uint16_t width = standard_sizes::buttonWidth, uint16_t height = standard_sizes::buttonHeight);

		Button(const std::wstring& buttonName, const std::wstring& buttonText, int x, int y, BaseComponent* parent, const std::string& functionName, const std::string& moduleName, uint16_t width = standard_sizes::buttonWidth, uint16_t height = standard_sizes::buttonHeight);

		size_t getHash() const override;

		~Button() = default;
	};
}
