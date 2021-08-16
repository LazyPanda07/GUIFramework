#pragma once

#include "pch.h"

namespace gui_framework
{
	namespace interfaces
	{
		/// @brief Provides adding, deleting, setting, getting items for other list view interfaces
		class GUI_FRAMEWORK_API IBaseListViewOperations
		{
		private:
			HWND listViewHandle;
			size_t listViewSize;

		protected:
			virtual LRESULT addItem(const LVITEMW& item);

			virtual LRESULT setItem(const LVITEMW& item);

			virtual void getItem(LVITEMW& item) const;

		public:
			IBaseListViewOperations(HWND handle);

			virtual bool deleteItem(size_t index) final;

			virtual size_t size() const final;

			virtual ~IBaseListViewOperations() = default;
		};
	}
}
