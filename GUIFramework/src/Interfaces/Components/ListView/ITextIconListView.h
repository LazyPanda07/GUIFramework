#pragma once

#include "IBaseListViewOperations.h"
#include "Utility/Holders/IconsHolder.h"

namespace gui_framework
{
	namespace interfaces
	{
		class GUI_FRAMEWORK_API ITextIconListView : public IBaseListViewOperations
		{
		private:
			utility::IconsHolder& icons;

		public:
			ITextIconListView(HWND handle, utility::IconsHolder& icons);

			virtual LRESULT addTextIconItem(const std::wstring& text, const std::filesystem::path& pathToIcon);

			virtual ~ITextIconListView() = default;
		};
	}
}
