#pragma once

#include "BaseComponents/StandardComponents/BaseInfiniteProgressBar.h"
#include "BaseComponents/BaseResizableComponent.h"

#pragma warning(push)
#pragma warning(disable: 4250)

namespace gui_framework
{
	class GUI_FRAMEWORK_API InfiniteProgressBar :
		public BaseInfiniteProgressBar,
		virtual public BaseResizableComponent
	{
	public:
		InfiniteProgressBar(const std::wstring& progressBarName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent);

		~InfiniteProgressBar() = default;
	};
}

#pragma warning(pop)
