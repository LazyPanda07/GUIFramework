#pragma once

#include "Utility/Creators/BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief TextListView creator
		class GUI_FRAMEWORK_API TextListViewCreator : public BaseComponentCreator
		{
		public:
			TextListViewCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComposite* parent) override;

			~TextListViewCreator() = default;
		};
	}
}
