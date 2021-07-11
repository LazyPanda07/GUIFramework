#pragma once

#include "pch.h"

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
			ITextOperations(HWND handle);

			virtual void setText(const std::wstring& text) const final;

			/// @brief Get text from control
			/// @return Text from control
			/// @exception GetLastErrorException
			virtual std::wstring getText() const final;

			virtual ~ITextOperations() = default;
		};
	}
}
