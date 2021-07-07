#pragma once

#include "BaseComponents/StandardComponents/BaseProgressBar.h"
#include "BaseComponents/BaseResizableComponent.h"

#pragma warning(push)
#pragma warning(disable: 4250)

namespace gui_framework
{
	class GUI_FRAMEWORK_API ProgressBar :
		public BaseProgressBar,
		virtual public BaseResizableComponent
	{
	public:
		ProgressBar(const std::wstring& progressBarName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent);

		~ProgressBar() = default;
	};
}

#pragma warning(pop)
