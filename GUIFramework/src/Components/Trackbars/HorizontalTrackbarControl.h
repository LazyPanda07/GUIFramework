#pragma once

#include "BaseComponents/StandardComponents/BaseTrackbarControl.h"

namespace gui_framework
{
	/// @brief Standard horizontal trackbar control
	class GUI_FRAMEWORK_API HorizontalTrackbarControl : public BaseTrackbarControl
	{
	public:
		enum class horizontalTickPosition
		{
			top,
			bottom,
			both
		};

	public:
		HorizontalTrackbarControl(const std::wstring& trackbarName, const utility::ComponentSettings& settings, BaseComposite* parent, bool autoTicks = true, horizontalTickPosition position = horizontalTickPosition::bottom, bool selectionRange = false, bool noTicks = false);

		size_t getHash() const override;

		json::JSONBuilder getStructure() const override;

		~HorizontalTrackbarControl() = default;
	};
}
