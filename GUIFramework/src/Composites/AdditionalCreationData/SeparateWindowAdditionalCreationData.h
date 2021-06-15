#pragma once

#include "AdditionalCreationData.h"
#include "Composites/SeparateWindow.h"

namespace gui_framework
{
	namespace utility
	{
		template<>
		class AdditionalCreationData<SeparateWindow>
		{
		protected:
			std::wstring className;
			std::string functionName;

		public:
			AdditionalCreationData() = default;

			AdditionalCreationData(const std::wstring& className, const std::string& functionName);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};
	}
}