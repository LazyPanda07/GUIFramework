#pragma once

#include "IBaseListViewOperations.h"

namespace gui_framework
{
	namespace interfaces
	{
		/// @brief Provides adding text items for list views
		class GUI_FRAMEWORK_API ITextListView : public IBaseListViewOperations
		{
		public:
			ITextListView(HWND handle);

			virtual LRESULT addTextItem(const std::wstring& text);

			virtual std::wstring getItemText(size_t index) const;

			virtual ~ITextListView() = default;
		};
	}
}
