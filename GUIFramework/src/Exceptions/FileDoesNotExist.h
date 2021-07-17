#pragma once

#include "pch.h"
#include "BaseGUIFrameworkException.h"

namespace gui_framework
{
	namespace exceptions
	{
		/// @brief Throws by asset finding methods
		class GUI_FRAMEWORK_API FileDoesNotExist : public BaseGUIFrameworkException
		{
		public:
			FileDoesNotExist(const std::filesystem::path& filePath);

			~FileDoesNotExist() = default;
		};
	}
}
