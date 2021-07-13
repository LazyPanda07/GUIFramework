#pragma once

#include "BaseComponents/StandardComponents/BaseInfiniteProgressBar.h"
#include "Interfaces/Components/IResizableComponent.h"

namespace gui_framework
{
	/// @brief Standard non updatable progress bar
	class GUI_FRAMEWORK_API InfiniteProgressBar :
		public BaseInfiniteProgressBar,
		public interfaces::IResizableComponent
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
