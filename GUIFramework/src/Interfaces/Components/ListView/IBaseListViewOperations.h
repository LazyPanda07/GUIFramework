#pragma once

#include "pch.h"

namespace gui_framework
{
	namespace interfaces
	{
		class GUI_FRAMEWORK_API IBaseListViewOperations
		{
		private:
			HWND listViewHandle;

		protected:
			virtual LRESULT addItem(const LVITEMW& item);

		public:
			IBaseListViewOperations(HWND handle);

			virtual ~IBaseListViewOperations() = default;
		};
	}
}
