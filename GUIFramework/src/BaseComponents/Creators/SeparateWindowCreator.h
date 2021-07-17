#pragma once

#include "pch.h"
#include "BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief SeparateWindow creator
		class GUI_FRAMEWORK_API SeparateWindowCreator : public BaseComponentCreator
		{
		public:
			SeparateWindowCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent = nullptr) override;

			~SeparateWindowCreator() = default;
		};
	}
}
