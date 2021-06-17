#pragma once

#include "BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief gui_framework::SeparateWindow creator
		class GUI_FRAMEWORK_API SeparateWindowCreator : public BaseComponentCreator
		{
		public:
			SeparateWindowCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent = nullptr) override;

			~SeparateWindowCreator() = default;
		};
	}
}