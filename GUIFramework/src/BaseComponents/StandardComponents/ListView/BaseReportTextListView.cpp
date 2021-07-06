#include "pch.h"
#include "BaseReportTextListView.h"

using namespace std;

namespace gui_framework
{
	void BaseReportTextListView::addRow()
	{
		LVITEMW item = {};

		item.iItem = rowCount;

		if (SendMessageW(handle, LVM_INSERTITEM, NULL, reinterpret_cast<LPARAM>(&item)) != -1)
		{
			rowCount++;
		}
	}

	BaseReportTextListView::BaseReportTextListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseComponent
		(
			wstring(standard_classes::listView),
			listViewName,
			utility::ComponentSettings
			(
				settings.styles | LVS_REPORT,
				settings.x,
				settings.y,
				settings.width,
				settings.height,
				settings.extendedStyles
			),
			parent
		),
		BaseReportListView
		(
			listViewName,
			utility::ComponentSettings
			(
				settings.styles,
				settings.x,
				settings.y,
				settings.width,
				settings.height,
				settings.extendedStyles
			),
			parent
		),
		ITextListView(handle),
		columnCount(0),
		rowCount(0)
	{

	}

	LRESULT BaseReportTextListView::addTextItem(const wstring& text)
	{
		LVCOLUMNW item = {};
		SIZE sizes;

		GetTextExtentPoint32W(GetDC(handle), text.data(), static_cast<int>(text.size()), &sizes);

		item.mask = LVCF_TEXT | LVCF_WIDTH;
		item.pszText = const_cast<wchar_t*>(text.data());
		item.cchTextMax = static_cast<int>(text.size());
		item.cx = sizes.cx + standard_sizes::additionalListViewReportColumnWidth;

		LRESULT result = SendMessageW(handle, LVM_INSERTCOLUMN, columnCount, reinterpret_cast<LPARAM>(&item));

		if (result != -1)
		{
			SendMessageW(handle, LVM_ISITEMVISIBLE, result, NULL);

			columnCount++;
		}

		return result;
	}

	LRESULT BaseReportTextListView::addTextItem(const wstring& text, int columnIndex, int rowIndex)
	{
		LVITEMW item = {};

		item.mask = LVCF_TEXT;
		item.pszText = const_cast<wchar_t*>(text.data());
		item.cchTextMax = static_cast<int>(text.size());
		item.iSubItem = columnIndex;

		while (rowCount <= rowIndex)
		{
			this->addRow();
		}

		return SendMessageW(handle, LVM_SETITEMTEXT, rowIndex, reinterpret_cast<LPARAM>(&item));
	}

	int BaseReportTextListView::getRowCount() const
	{
		return rowCount;
	}

	int BaseReportTextListView::getColumnCount() const
	{
		return columnCount;
	}
}
