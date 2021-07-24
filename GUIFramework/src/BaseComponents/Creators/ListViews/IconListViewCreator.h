#pragma once

#include "pch.h"
#include "BaseComponents/Creators/BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief IconListView creator
		class GUI_FRAMEWORK_API IconListViewCreator : public BaseComponentCreator
		{
		public:
			IconListViewCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent) override;

			~IconListViewCreator() = default;
		};
	}
}
