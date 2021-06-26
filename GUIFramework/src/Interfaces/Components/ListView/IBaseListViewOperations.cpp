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

		IBaseListViewOperations::IBaseListViewOperations(HWND handle) :
			listViewHandle(handle)
		{

		}
	}
}
