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

			void setText(const std::wstring& text);

			virtual void setText(const std::string& localizationKey);

			/// @brief Get text from control
			/// @return Text from control
			/// @exception GetLastErrorException
			virtual std::wstring getText() const final;

			virtual ~ITextOperations() = default;
		};
	}
}
