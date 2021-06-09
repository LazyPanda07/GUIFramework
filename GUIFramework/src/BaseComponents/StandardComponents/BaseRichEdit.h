#pragma once

#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Components/IResizableComponent.h"
#include "Interfaces/Components/ITextOperations.h"

namespace gui_framework
{
	class BaseRichEdit :
		virtual public BaseComponent,
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
		std::unordered_map<urlDetectEvent, std::function<void(const std::wstring&)>> callbacks;

	protected:
		virtual LRESULT windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) override;

	public:
		BaseRichEdit(const std::wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent);

		virtual void addUrlDetectEvent(urlDetectEvent event, const std::function<void(const std::wstring&)>& eventCallback) final;

		virtual void removeUrlDetectEvent(urlDetectEvent event) final;

		virtual void setAutoURLDetect(bool autoURLDetect) final;

		virtual bool getAutoURLDetect() const final;

		virtual ~BaseRichEdit() = default;
	};
}
