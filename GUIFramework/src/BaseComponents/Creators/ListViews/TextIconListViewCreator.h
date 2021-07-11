#pragma once

#include "BaseComponents/Creators/BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief TextIconListView creator
		class GUI_FRAMEWORK_API TextIconListViewCreator : public BaseComponentCreator
		{
		public:
			TextIconListViewCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent) override;

			~TextIconListViewCreator() = default;
		};
	}
}
