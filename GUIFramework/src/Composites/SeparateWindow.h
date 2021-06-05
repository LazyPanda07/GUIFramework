#pragma once

#include "BaseComposites/BaseSeparateWindow.h"

namespace gui_framework
{
	class SeparateWindow : public BaseSeparateWindow
	{
	public:
		SeparateWindow(const std::wstring& className, const std::wstring& titleName, const utility::ComponentSettings& settings, const std::string& windowFunctionName);

		~SeparateWindow() = default;
	};
}
