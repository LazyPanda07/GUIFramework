#pragma once

#include "IBaseListViewOperations.h"
#include "Utility/ImagesHolder.h"

namespace gui_framework
{
	namespace interfaces
	{
		class GUI_FRAMEWORK_API ITextIconListView : public IBaseListViewOperations
		{
		private:
			utility::ImagesHolder& images;

		public:
			ITextIconListView(HWND handle, utility::ImagesHolder& images);

			virtual LRESULT addTextIconItem(const std::wstring& text, const std::filesystem::path& pathToIcon);

			virtual ~ITextIconListView() = default;
		};
	}
}
