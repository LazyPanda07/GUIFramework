#include "pch.h"
#include "IPlaceholder.h"

using namespace std;

namespace gui_framework
{
	namespace interfaces
	{
		IPlaceholder::IPlaceholder(HWND placeholderHandle, const wstring& placeholderText) :
			placeholderHandle(placeholderHandle)
		{
			if (placeholderText.size())
			{
				if (this->setPlaceholder(placeholderText))
				{
					this->currentPlaceholderText = placeholderText;
				}
			}
		}

		bool IPlaceholder::setPlaceholder(const wstring& placeholderText)
		{
			bool result = SendMessageW(placeholderHandle, EM_SETCUEBANNER, false, reinterpret_cast<LPARAM>(placeholderText.data()));

			if (result)
			{
				currentPlaceholderText = placeholderText;
			}

			return result;
		}

		const wstring& IPlaceholder::getPlaceholder() const
		{
			return currentPlaceholderText;
		}

	}
}
