#pragma once

#include "BaseGUIFrameworkException.h"

namespace gui_framework
{
	namespace exceptions
	{
		class GUI_FRAMEWORK_API FileDoesNotExist : public BaseGUIFrameworkException
		{
		public:
			FileDoesNotExist(const std::filesystem::path& filePath);

			~FileDoesNotExist() = default;
		};
	}
}
