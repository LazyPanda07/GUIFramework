#pragma once

#include "pch.h"
#include "AdditionalCreationData.h"
#include "Composites/ChildWindow.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Specialization for ChildWindow
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<ChildWindow>
		{
		protected:
			std::wstring className;
			std::string functionName;

		public:
			AdditionalCreationData() = default;

			AdditionalCreationData(const std::wstring& className, const std::string& functionName = "");

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};
	}
}
