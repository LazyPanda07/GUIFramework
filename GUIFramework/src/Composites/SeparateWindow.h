#pragma once

#include "BaseComposites/BaseSeparateWindow.h"
#include "BaseComposites/BaseResizableComposite.h"

namespace gui_framework
{
	class SeparateWindow :
		public BaseResizableComposite,
		public BaseSeparateWindow
	{
	public:
		SeparateWindow(const std::wstring& className, const std::wstring& titleName, const utility::ComponentSettings& settings, const std::string& windowFunctionName);

		~SeparateWindow() = default;
	};
}
