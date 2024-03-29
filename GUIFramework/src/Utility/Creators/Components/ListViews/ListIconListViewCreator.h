#pragma once

#include "Utility/Creators/BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief ListIconListView creator
		class GUI_FRAMEWORK_API ListIconListViewCreator : public BaseComponentCreator
		{
		public:
			ListIconListViewCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComposite* parent) override;

			~ListIconListViewCreator() = default;
		};
	}
}
