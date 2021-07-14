#pragma once

#include "pch.h"

namespace gui_framework
{
	namespace interfaces
	{
		/// @brief Provides resize, setBlockResize, getBlockResize methods
		class GUI_FRAMEWORK_API IResizableComponent
		{
		private:
			HWND resizeableHandle;
			HWND parent;

		protected:
			bool blockResize;
			bool autoResize;
			int initX;
			int initY;
			uint16_t initWidth;
			uint16_t initHeight;
			uint16_t parentWidth;
			uint16_t parentHeight;

		public:
			IResizableComponent(HWND resizeableHandle, HWND parent, bool autoResize = false, bool blockResize = false);

			/// @brief Resize component
			/// @param width New width of the client area
			/// @param height New height of the client area
			virtual void resize(uint16_t width, uint16_t height);

			virtual RECT calculateNewSizes(uint16_t width, uint16_t height) final;

			virtual void setBlockResize(bool blockResize) final;

			virtual void setAutoResize(bool autoResize) final;

			virtual bool getBlockResize() const final;

			virtual bool getAutoResize() const final;

			virtual ~IResizableComponent() = default;
		};
	}
}
