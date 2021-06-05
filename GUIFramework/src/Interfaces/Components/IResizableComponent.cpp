#include "pch.h"
#include "IResizableComponent.h"

using namespace std;

namespace gui_framework
{
	namespace interfaces
	{
		IResizableComponent::IResizableComponent(HWND resizeableHandle, HWND parent, bool autoResize, bool blockResize) :
			resizeableHandle(resizeableHandle),
			parent(parent),
			autoResize(autoResize),
			blockResize(blockResize)
		{
			RECT sizes;

			GetWindowRect(resizeableHandle, &sizes);

			initWidth = static_cast<uint16_t>(sizes.right) - static_cast<uint16_t>(sizes.left);
			initHeight = static_cast<uint16_t>(sizes.bottom) - static_cast<uint16_t>(sizes.top);

			GetClientRect(resizeableHandle, &sizes);

			MapWindowPoints(HWND_DESKTOP, parent ? parent : HWND_DESKTOP, reinterpret_cast<POINT*>(&sizes), 2);

			initX = sizes.left;
			initY = sizes.top;
		}

		void IResizableComponent::resize(uint16_t width, uint16_t height)
		{
			if (autoResize)
			{
				RECT newSizes = this->calculateNewSizes(width, height);

				MoveWindow
				(
					resizeableHandle,
					newSizes.left,
					newSizes.top,
					newSizes.right - newSizes.left,
					newSizes.bottom - newSizes.top,
					true
				);

				ShowWindow(resizeableHandle, SW_SHOW);
			}
		}

		RECT IResizableComponent::calculateNewSizes(uint16_t width, uint16_t height)
		{
			RECT result;

			double widthCoefficient = static_cast<double>(width) / initWidth;
			double heightCoefficient = static_cast<double>(height) / initHeight;

			result.left = static_cast<uint16_t>(widthCoefficient * initX);
			result.top = static_cast<uint16_t>(heightCoefficient * initY);

			result.right = static_cast<uint16_t>(result.left + widthCoefficient * width);
			result.bottom = static_cast<uint16_t>(result.top + heightCoefficient * height);

			return result;
		}

		void IResizableComponent::setBlockResize(bool blockResize)
		{
			this->blockResize = blockResize;
		}

		void IResizableComponent::setAutoResize(bool autoResize)
		{
			this->autoResize = autoResize;
		}

		bool IResizableComponent::getBlockResize() const
		{
			return blockResize;
		}

		bool IResizableComponent::getAutoResize() const
		{
			return autoResize;
		}
	}
}
