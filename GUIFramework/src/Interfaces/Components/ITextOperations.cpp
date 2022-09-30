#include "Core.h"
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

		void ITextOperations::setText(const wstring& text)
		{
			SetWindowTextW(textHandle, text.data());
		}

		void ITextOperations::setText(const string& localizationKey)
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
