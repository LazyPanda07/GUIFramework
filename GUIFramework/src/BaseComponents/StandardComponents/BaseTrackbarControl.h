#pragma once

#include "BaseComponents/BaseComponent.h"
#include "Styles/Components/Trackbars/TrackbarControlStyles.h"

namespace gui_framework
{
	/// @brief Base class for all tracbar controls
	class GUI_FRAMEWORK_API BaseTrackbarControl : public BaseComponent
	{
	public:
		BaseTrackbarControl(const std::wstring& trackbarName, const utility::ComponentSettings& settings, const styles::TrackbarControlStyles& styles, BaseComponent* parent);

		virtual void clearSelection() final;

		virtual LRESULT size() const final;

		virtual void setMinRange(int min) final;

		virtual void setMaxRange(int max) final;

		virtual void setSelectionStart(int startPosition) final;

		virtual void setSelectionEnd(int endPosition) final;

		virtual LRESULT getPosition() const final;

		virtual LRESULT getMinRange() const final;

		virtual LRESULT getMaxRange() const final;

		virtual LRESULT getSelectionStart() const final;

		virtual LRESULT getSelectionEnd() const final;

		/// @brief Not implemented
		/// @param red 
		/// @param green 
		/// @param blue 
		/// @exception NotImplemented Text color does not affects at track bars
		virtual void setTextColor(uint8_t red, uint8_t green, uint8_t blue) final override;

		virtual ~BaseTrackbarControl() = default;
	};
}
