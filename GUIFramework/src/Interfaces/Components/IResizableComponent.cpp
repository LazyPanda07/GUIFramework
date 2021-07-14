#include "pch.h"
#include "IResizableComponent.h"

#pragma warning(disable: 6387)

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
			utility::appendStyle(resizeableHandle, WS_THICKFRAME);

			RECT sizes;

			GetClientRect(parent ? parent : HWND_DESKTOP, &sizes);

			parentWidth = static_cast<uint16_t>(sizes.right) - static_cast<uint16_t>(sizes.left);
			parentHeight = static_cast<uint16_t>(sizes.bottom) - static_cast<uint16_t>(sizes.top);

			GetWindowRect(resizeableHandle, &sizes);

			initWidth = static_cast<uint16_t>(sizes.right) - static_cast<uint16_t>(sizes.left);
			initHeight = static_cast<uint16_t>(sizes.bottom) - static_cast<uint16_t>(sizes.top);

			MapWindowPoints(HWND_DESKTOP, parent ? parent : HWND_DESKTOP, reinterpret_cast<POINT*>(&sizes), 2);

			initX = sizes.left;
			initY = sizes.top;
		}

		void IResizableComponent::resize(uint16_t width, uint16_t height)
		{
			if (autoResize && !blockResize)
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

			double widthCoefficient = static_cast<double>(width) / parentWidth;
			double heightCoefficient = static_cast<double>(height) / parentHeight;

			result.left = static_cast<int>(widthCoefficient * initX);
			result.top = static_cast<int>(heightCoefficient * initY);

			result.right = static_cast<int>(result.left + widthCoefficient * initWidth);
			result.bottom = static_cast<int>(result.top + heightCoefficient * initHeight);

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
