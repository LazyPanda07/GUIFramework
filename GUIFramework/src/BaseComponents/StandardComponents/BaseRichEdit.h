#pragma once

#include "headers.h"
#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Components/IResizableComponent.h"
#include "Interfaces/Components/ITextOperations.h"

namespace gui_framework
{
	/// @brief Base class for all rich edit controls
	class GUI_FRAMEWORK_API BaseRichEdit :
		public BaseComponent,
		public interfaces::IResizableComponent,
		public interfaces::ITextOperations
	{
	public:
		enum class urlDetectEvent
		{
			mouseMove = WM_MOUSEMOVE,
			leftButtonDown,
			leftButtonUp,
			leftButtonDoubleClick,
			rightButtonDown,
			rightButtonUp,
			rightButtonDoubleClick,
			setCursor = WM_SETCURSOR
		};

		static constexpr uint8_t urlDetectEventSize = 8;

	protected:
		std::array<std::function<void(const std::wstring&)>, urlDetectEventSize> callbacks;
		std::array<std::pair<std::string, std::string>, urlDetectEventSize> callbacksFunctionNamesAndModules;	// function name - module name
		bool isMultiLine;
		uint64_t limitTextCount;

	private:
		void addCallback(urlDetectEvent event, const std::function<void(const std::wstring&)>& callback, const std::string& functionName, const std::string& moduleName);

	protected:
		virtual LRESULT windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) override;

	public:
		BaseRichEdit(const std::wstring& richEditName, const utility::ComponentSettings& settings, BaseComponent* parent, bool isMultiLine = false);

		virtual void addUrlDetectEvent(urlDetectEvent event, const std::function<void(const std::wstring&)>& eventCallback) final;

		virtual void addUrlDetectEvent(urlDetectEvent event, const std::string& functionName, const std::string& moduleName) final;

		virtual void removeUrlDetectEvent(urlDetectEvent event) final;

		virtual LRESULT findSubstring(const std::wstring& subStringToFind, bool isMatchCase = true) final;

		virtual LRESULT findString(const std::wstring& stringToFind, bool isMatchCase = true) final;

		virtual void setAutoURLDetect(bool autoURLDetect) final;

		virtual void setLimitText(uint64_t count) final;

		virtual bool getAutoURLDetect() const final;

		virtual std::wstring getSelectedText() const final;

		virtual const std::function<void(const std::wstring&)>& getCallback(urlDetectEvent event) const final;

		virtual bool getIsMultiLine() const final;

		virtual void setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue) final override;

		virtual void setTextColor(uint8_t red, uint8_t green, uint8_t blue) final override;

		/// @brief Used as key in creators
		/// @return typeid().hash_code()
		virtual size_t getHash() const override = 0;

		virtual json::JSONBuilder getStructure() const override;

		virtual ~BaseRichEdit() = default;
	};

	/// @brief Used in rich edit auto url detect events
	using richEditCallbackSignature = void(*)(const std::wstring&);
}
