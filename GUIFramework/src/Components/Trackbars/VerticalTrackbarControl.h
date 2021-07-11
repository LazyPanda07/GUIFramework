#pragma once

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
		VerticalTrackbarControl(const std::wstring& trackbarName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, bool autoTicks = true, verticalTickPosition position = verticalTickPosition::left, bool selectionRange = false, bool noTicks = false);

		~VerticalTrackbarControl() = default;
	};
}
