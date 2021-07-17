#pragma once

#include "pch.h"
#include "AdditionalCreationData.h"
#include "Components/RichEdit.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Specialization for RichEdit
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<RichEdit>
		{
		protected:
			std::vector<std::pair<BaseRichEdit::urlDetectEvent, std::function<void(const std::wstring&)>>> callbacks;
			uint64_t textLimitCount;
			bool isMultiLine;

		public:
			AdditionalCreationData(const std::vector<std::pair<BaseRichEdit::urlDetectEvent, std::function<void(const std::wstring&)>>>& callbacks = {}, uint64_t textLimitCount = 0, bool isMultiLine = false);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};
	}
}
