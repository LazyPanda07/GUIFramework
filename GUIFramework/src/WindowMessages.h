#pragma once

namespace gui_framework
{
	namespace custom_window_messages
	{
		/// @brief WPARAM contains BaseComposite*
		inline constexpr uint32_t initTopLevelWindowPointer = 52430;

		/// @brief Set to nullptr topLevelWindow for recreating window with same window class name
		inline constexpr uint32_t deinitTopLevelWindowPointer = initTopLevelWindowPointer + 1;

		/**
		 * @brief WRAPAM contains std::function<void()>*
		*/
		inline constexpr uint32_t runOnUIThreadFunctions = deinitTopLevelWindowPointer + 1;

		/**
		 * @brief Used by GUIFramework and BaseMainWindow internally
		*/
		inline constexpr uint32_t startTrayId = runOnUIThreadFunctions + 1;
	}
}
