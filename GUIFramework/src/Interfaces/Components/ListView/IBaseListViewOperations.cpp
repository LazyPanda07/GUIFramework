#include "pch.h"
#include "IBaseListViewOperations.h"

using namespace std;

namespace gui_framework
{
	namespace interfaces
	{
		LRESULT IBaseListViewOperations::addItem(const LVITEMW& item)
		{
			LRESULT result = SendMessageW(listViewHandle, LVM_INSERTITEM, NULL, reinterpret_cast<LPARAM>(&item));

			if (result != -1)
			{
				SendMessageW(listViewHandle, LVM_ISITEMVISIBLE, result, NULL);
			}

			return result;
		}

		LRESULT IBaseListViewOperations::setItem(const LVITEMW& item)
		{
			return SendMessageW(listViewHandle, LVM_SETITEM, NULL, reinterpret_cast<LPARAM>(&item));
		}

		void IBaseListViewOperations::getItem(LVITEMW& item) const
		{
			SendMessageW(listViewHandle, LVM_GETITEMW, NULL, reinterpret_cast<LPARAM>(&item));
		}

		IBaseListViewOperations::IBaseListViewOperations(HWND handle) :
			listViewHandle(handle)
		{

		}

		bool IBaseListViewOperations::deleteItem(size_t index)
		{
			return SendMessageW(listViewHandle, LVM_DELETEITEM, index, NULL);
		}
	}
}
