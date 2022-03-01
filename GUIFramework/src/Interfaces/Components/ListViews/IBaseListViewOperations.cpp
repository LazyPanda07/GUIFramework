#include "headers.h"
#include "IBaseListViewOperations.h"

using namespace std;

namespace gui_framework
{
	namespace interfaces
	{
		void IBaseListViewOperations::onRemove(size_t index)
		{

		}

		LRESULT IBaseListViewOperations::addItem(const LVITEMW& item)
		{
			LRESULT result = SendMessageW(listViewHandle, LVM_INSERTITEM, NULL, reinterpret_cast<LPARAM>(&item));

			if (result != -1)
			{
				SendMessageW(listViewHandle, LVM_ISITEMVISIBLE, result, NULL);

				listViewSize++;
			}

			return result;
		}

		LRESULT IBaseListViewOperations::setItem(const LVITEMW& item)
		{
			LRESULT result = SendMessageW(listViewHandle, LVM_SETITEM, NULL, reinterpret_cast<LPARAM>(&item));

			if (result != -1)
			{
				SendMessageW(listViewHandle, LVM_ISITEMVISIBLE, result, NULL);
			}

			return result;
		}

		void IBaseListViewOperations::getItem(LVITEMW& item) const
		{
			SendMessageW(listViewHandle, LVM_GETITEMW, NULL, reinterpret_cast<LPARAM>(&item));
		}

		IBaseListViewOperations::IBaseListViewOperations(HWND handle) :
			listViewHandle(handle),
			listViewSize(0)
		{

		}

		bool IBaseListViewOperations::removeItem(size_t index)
		{
			bool result = SendMessageW(listViewHandle, LVM_DELETEITEM, index, NULL);

			if (result)
			{
				listViewSize--;

				this->onRemove(index);
			}

			return result;
		}

		size_t IBaseListViewOperations::size() const
		{
			return listViewSize;
		}
	}
}
