#pragma once

#include "Core.h"

namespace gui_framework
{
	namespace interfaces
	{
		/// @brief Provides preventing resize
		class GUI_FRAMEWORK_API INonResizableComponent
		{
		private:
			HWND nonResizableHandle;

		public:
			INonResizableComponent(HWND nonResizableHandle);

			/// @brief Reserve resize function
			/// @param width 
			/// @param height 
			/// @exception NotImplemented 
			virtual void resize(uint16_t width, uint16_t height) final;

			virtual ~INonResizableComponent() = default;
		};
	}
}
