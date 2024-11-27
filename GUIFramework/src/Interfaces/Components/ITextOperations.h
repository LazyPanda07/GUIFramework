#pragma once

#include "Core.h"

namespace gui_framework
{
	namespace interfaces
	{
		/// @brief Provides setText and getText methods
		class GUI_FRAMEWORK_API ITextOperations
		{
		protected:
			HWND textHandle;

		public:
			ITextOperations(HWND handle, const std::wstring& text = L"");

			ITextOperations(HWND handle, const std::string& localizationKey);

			void setText(std::wstring_view text);

			virtual void setText(std::string_view localizationKey);

			/// @brief Get text from control
			/// @return Text from control
			/// @exception GetLastErrorException
			virtual std::wstring getText() const final;

			virtual ~ITextOperations() = default;
		};
	}
}
