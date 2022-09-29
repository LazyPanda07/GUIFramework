#pragma once

#include "core.h"
#include "Utility/Creators/BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief ListTextIconListView creator
		class GUI_FRAMEWORK_API ListTextIconListViewCreator : public BaseComponentCreator
		{
		public:
			ListTextIconListViewCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent) override;

			~ListTextIconListViewCreator() = default;
		};
	}
}
