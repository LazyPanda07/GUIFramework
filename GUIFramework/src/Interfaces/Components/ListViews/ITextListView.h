#pragma once

#include "pch.h"
#include "IBaseListViewOperations.h"

namespace gui_framework
{
	namespace interfaces
	{
		/// @brief Provides adding text items for list views
		class GUI_FRAMEWORK_API ITextListView : public IBaseListViewOperations
		{
		private:
			virtual void onRemove(size_t index) final override;

		private:
			std::unordered_map<size_t, size_t> textData;	// index - size

		public:
			ITextListView(HWND handle);

			virtual LRESULT addTextItem(const std::wstring& text);

			virtual LRESULT insertTextItem(const std::wstring& text, size_t index);

			virtual std::wstring getItemText(size_t index) const;

			virtual ~ITextListView() = default;
		};
	}
}
