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
		/// @brief 
		/// @param progressBarName 
		/// @param x 
		/// @param y 
		/// @param width 
		/// @param height 
		/// @param parent 
		/// @param animationPeriod Period between animation in milliseconds
		InfiniteProgressBar(const std::wstring& progressBarName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, int animationPeriod = NULL);

		~InfiniteProgressBar() = default;
	};
}

#pragma warning(pop)
