#pragma once

#include "pch.h"

namespace gui_framework
{
	namespace interfaces
	{
		class IPlaceholder
		{
		protected:
			HWND placeholderHandle;
			std::wstring currentPlaceholderText;

		public:
			IPlaceholder(HWND placeholderHandle, const std::wstring& placeholderText = L"");

			virtual bool setPlaceholder(const std::wstring& placeholderText) final;

			virtual const std::wstring& getPlaceholder() const final;

			virtual ~IPlaceholder() = default;
		};
	}
}
