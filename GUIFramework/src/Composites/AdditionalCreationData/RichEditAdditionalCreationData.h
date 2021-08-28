#pragma once

#include "headers.h"
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
			std::array<std::function<void(const std::wstring&)>, BaseRichEdit::urlDetectEventSize> callbacks;
			std::array<std::pair<std::string, std::string>, BaseRichEdit::urlDetectEventSize> callbacksFunctionNamesAndModules;	// function name - module name
			uint64_t textLimitCount;
			bool isMultiLine;

		public:
			/// @brief Each index in array equals to urlDetectEvent value % 8, except urlDetectEvent::setCursor must be 7 index
			/// @param callbacks 
			/// @param textLimitCount 
			/// @param isMultiLine 
			AdditionalCreationData(const std::array<std::function<void(const std::wstring&)>, BaseRichEdit::urlDetectEventSize>& callbacks = {}, uint64_t textLimitCount = 0, bool isMultiLine = false);

			/// @brief Each index in array equals to urlDetectEvent value % 8, except urlDetectEvent::setCursor must be 7 index
			/// @param callbacksFunctionNamesAndModules Function name - module name
			/// @param textLimitCount 
			/// @param isMultiLine 
			AdditionalCreationData(const std::array<std::pair<std::string, std::string>, BaseRichEdit::urlDetectEventSize>& callbacksFunctionNamesAndModules = {}, uint64_t textLimitCount = 0, bool isMultiLine = false);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};
	}
}
