#pragma once

namespace gui_framework
{
	namespace custom_window_messages
	{
		/// @brief WPARAM contains BaseComposite*
		inline constexpr uint32_t initTopLevelWindowPointer = 52430;

		/// @brief Set to nullptr topLevelWindow for recreating window with same window class name
		inline constexpr uint32_t deinitTopLevelWindowPointer = initTopLevelWindowPointer + 1;

		/// <summary>
		/// WRAPAM contains std::function&lt;void()&gt;*
		/// </summary>
		inline constexpr uint32_t runOnUIThreadFunctions = deinitTopLevelWindowPointer + 1;
	}
}
