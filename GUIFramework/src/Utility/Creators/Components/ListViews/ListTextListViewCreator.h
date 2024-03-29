#pragma once

#include "Utility/Creators/BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief ListTextListView creator
		class GUI_FRAMEWORK_API ListTextListViewCreator : public BaseComponentCreator
		{
		public:
			ListTextListViewCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComposite* parent) override;

			~ListTextListViewCreator() = default;
		};
	}
}
