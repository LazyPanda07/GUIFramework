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

			GetClientRect(resizeableHandle, &sizes);

			initWidth = sizes.right - sizes.left;
			initHeight = sizes.bottom - sizes.top;

			GetWindowRect(resizeableHandle, &sizes);

			initX = sizes.left;
			initY = sizes.top;
		}

		void IResizableComponent::resize(uint16_t width, uint16_t height)
		{
			if (autoResize)
			{
				RECT newSizes = this->calculateNewSizes(width, height);

				SetWindowPos
				(
					resizeableHandle,
					HWND_BOTTOM,
					newSizes.left,
					newSizes.top,
					newSizes.right - newSizes.left,
					newSizes.bottom - newSizes.top,
					SWP_SHOWWINDOW
				);
			}
		}

		RECT IResizableComponent::calculateNewSizes(uint16_t width, uint16_t height)
		{
			RECT result;

			double widthCoefficient = static_cast<double>(width) / initWidth;
			double heightCoefficient =  static_cast<double>(height) / initHeight;

			result.left = widthCoefficient * initX;
			result.top = heightCoefficient * initY;

			result.right = result.left + widthCoefficient * width;
			result.bottom = result.top + heightCoefficient * height;

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
