#include "pch.h"
#include "IResizableComponent.h"

using namespace std;

namespace gui_framework
{
	namespace interfaces
	{
		IResizableComponent::IResizableComponent(HWND resizeableHandle, HWND parent, bool blockResize) :
			resizeableHandle(resizeableHandle),
			parent(parent),
			blockResize(blockResize)
		{

		}

		void IResizableComponent::setBlockResize(bool blockResize)
		{
			this->blockResize = blockResize;
		}

		bool IResizableComponent::getBlockResize() const
		{
			return blockResize;
		}
	}
}
