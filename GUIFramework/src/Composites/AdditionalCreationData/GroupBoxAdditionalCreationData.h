#pragma once

#include "pch.h"
#include "AdditionalCreationData.h"
#include "Composites/GroupBox.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Specialization for GroupBox
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<GroupBox>
		{
		protected:
			std::wstring groupBoxClassName;
			std::string groupBoxFunctionName;
			std::vector<GroupBox::radioButtonData> data;

		public:
			AdditionalCreationData() = default;

			AdditionalCreationData(const std::wstring& groupBoxClassName, const std::string& groupBoxFunctionName, const std::vector<GroupBox::radioButtonData>& radioButtons);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};
	}
}
