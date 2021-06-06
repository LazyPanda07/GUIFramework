#include "pch.h"
#include "ITextOperations.h"

#include "Exceptions/GetLastErrorException.h"

using namespace std;

namespace gui_framework
{
	namespace interfaces
	{
		ITextOperations::ITextOperations(HWND handle) :
			textHandle(handle)
		{

		}

		void ITextOperations::setText(const wstring& text) const
		{
			SetWindowTextW(textHandle, text.data());
		}

		wstring ITextOperations::getText() const
		{
			int textLength = GetWindowTextLengthW(textHandle);
			wstring text;

			if (!textLength)
			{
				DWORD errorCode = GetLastError();

				if (errorCode)
				{
					throw exceptions::GetLastErrorException(errorCode);
				}
			}

			text.resize(++textLength);

			GetWindowTextW(textHandle, text.data(), textLength);

			text.pop_back();

			return text;
		}
	}
}
