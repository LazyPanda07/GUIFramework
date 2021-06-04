#pragma once

#include "pch.h"

namespace gui_framework
{
	namespace interfaces
	{
		/// @brief Provides resize, setBlockResize, getBlockResize methods
		class IResizableComponent
		{
		protected:
			HWND resizeableHandle;
			HWND parent;
			bool blockResize;

		public:
			IResizableComponent(HWND resizeableHandle, HWND parent, bool blockResize = false);

			/// @brief Resize component
			/// @param width New width of the client area
			/// @param height New height of the client area
			virtual void resize(uint16_t width, uint16_t height) = 0;

			virtual void setBlockResize(bool blockResize) final;

			virtual bool getBlockResize() const final;

			virtual ~IResizableComponent() = default;
		};
	}
}
