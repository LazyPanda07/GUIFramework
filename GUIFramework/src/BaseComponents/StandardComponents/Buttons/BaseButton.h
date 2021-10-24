#pragma once

#include "headers.h"
#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Components/ITextOperations.h"
#include "Styles/Components/Buttons/ButtonStyles.h"

namespace gui_framework
{
	/// @brief Base class for all buttons
	class GUI_FRAMEWORK_API BaseButton :
		public BaseComponent,
		public interfaces::ITextOperations
	{
	public:
		inline static constexpr uint16_t buttonWidth = 200;
		inline static constexpr uint16_t buttonHeight = 20;

	protected:
		std::function<void()> onClick;
		std::string functionName;
		std::string moduleName;

	protected:
		virtual LRESULT windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) override;

	public:
		BaseButton(const std::wstring& buttonName, const std::wstring& buttonText, const utility::ComponentSettings& settings, const styles::ButtonStyles& styles, BaseComponent* parent, const std::function<void()>& onClick = nullptr);

		/// @brief 
		/// @exception CantFindFunctionFromModuleException 
		/// @exception std::out_of_range Can't find moduleName in loaded modules
		BaseButton(const std::wstring& buttonName, const std::wstring& buttonText, const utility::ComponentSettings& settings, const styles::ButtonStyles& styles, BaseComponent* parent, const std::string& functionName, const std::string& moduleName);

		/// @brief Can't serialize
		/// @param onClick 
		virtual void setOnClick(const std::function<void()>& onClick) final;

		/// @brief Load function from module. Can be seriazlied
		/// @param functionName 
		/// @param moduleName 
		/// @exception CantFindFunctionFromModuleException 
		/// @exception std::out_of_range Can't find moduleName in loaded modules
		virtual void setOnClick(const std::string& functionName, const std::string& moduleName);

		virtual const std::function<void()>& getOnClick() const final;

		/// @brief Get onClick function name from loaded module
		/// @return functionName
		virtual const std::string& getFunctionName() const final;

		/// @brief Get onClick function associated module name
		/// @return moduleName 
		virtual const std::string& getModuleName() const final;

		/// @brief Not implemented
		/// @param red 
		/// @param green 
		/// @param blue 
		/// @exception NotImplemented Text color does not affects at button
		virtual void setTextColor(uint8_t red, uint8_t green, uint8_t blue) final override;

		/// @brief Used as key in creators
		/// @return typeid().hash_code()
		virtual size_t getHash() const override = 0;

		virtual json::JSONBuilder getStructure() const override;

		~BaseButton() = default;
	};
}
