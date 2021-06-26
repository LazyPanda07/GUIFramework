#pragma once

#include "IBaseListViewOperations.h"

namespace gui_framework
{
	namespace interfaces
	{
		class GUI_FRAMEWORK_API ITextListView : public IBaseListViewOperations
		{
		public:
			ITextListView(HWND handle);

			virtual LRESULT addTextItem(const std::wstring& text);

			virtual ~ITextListView() = default;
		};
	}
}
