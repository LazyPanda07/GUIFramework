#pragma once

#include "headers.h"
#include "BaseComponents/StandardComponents/BaseTrackbarControl.h"

namespace gui_framework
{
	/// @brief Standard vertical trackbar control
	class GUI_FRAMEWORK_API VerticalTrackbarControl : public BaseTrackbarControl
	{
	public:
		enum class verticalTickPosition
		{
			left,
			right,
			both
		};

	public:
		VerticalTrackbarControl(const std::wstring& trackbarName, const utility::ComponentSettings& settings, BaseComponent* parent, bool autoTicks = true, verticalTickPosition position = verticalTickPosition::left, bool selectionRange = false, bool noTicks = false);

		size_t getHash() const override;

		json::JSONBuilder getStructure() const override;

		~VerticalTrackbarControl() = default;
	};
}
