#include "ITextOperations.h"

#include "Exceptions/GetLastErrorException.h"

using namespace std;

namespace gui_framework
{
	namespace interfaces
	{
		ITextOperations::ITextOperations(HWND handle, const wstring& text) :
			textHandle(handle)
		{
			this->setText(text);
		}

		ITextOperations::ITextOperations(HWND handle, const string& localizationKey)
		{
			this->setText(localizationKey);
		}

		void ITextOperations::setText(wstring_view text)
		{
			SetWindowTextW(textHandle, text.data());
		}

		void ITextOperations::setText(string_view localizationKey)
		{
			this->setText(localization::WTextLocalization::get()[localizationKey]);
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
					throw exceptions::GetLastErrorException(errorCode, __FILE__, __FUNCTION__, __LINE__);
				}
			}

			text.resize(++textLength);

			GetWindowTextW(textHandle, text.data(), textLength);

			text.pop_back();

			return text;
		}
	}
}
