#include "pch.h"
#include "BaseEditControl.h"

#include "Exceptions/GetLastErrorException.h"

using namespace std;

namespace gui_framework
{
	BaseEditControl::BaseEditControl(const std::wstring& editControlName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseComponent
		(
			wstring(standard_classes::editControl),
			editControlName,
			settings,
			parent
		)
	{
		this->setText(L"");
	}

	void BaseEditControl::setText(const wstring& text) const
	{
		SetWindowTextW(handle, text.data());
	}

	wstring BaseEditControl::getText() const
	{
		int textLength = GetWindowTextLengthW(handle);
		wstring text;

		if (!textLength)
		{
			DWORD errorCode = GetLastError();

			if (!errorCode)
			{
				throw exceptions::GetLastErrorException(errorCode);
			}
		}

		text.resize(++textLength);

		GetWindowTextW(handle, text.data(), textLength);

		return text;
	}
}
