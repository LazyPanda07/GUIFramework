#pragma once

#include "BaseReportListView.h"
#include "Interfaces/Components/ListView/ITextListView.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API BaseReportTextListView :
		public BaseReportListView,
		public interfaces::ITextListView
	{
	protected:
		int rowCount;
		int columnCount;

	private:
		virtual void addRow() final;

	public:
		BaseReportTextListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent);

		/// @brief Add column with text header
		/// @param text 
		/// @return 
		virtual LRESULT addTextItem(const std::wstring& text) final override;

		/// @brief Add item to table
		/// @param text 
		/// @param columnIndex 
		/// @param rowIndex 
		/// @return 
		virtual LRESULT addTextItem(const std::wstring& text, int columnIndex, int rowIndex) final;

		virtual int getRowCount() const final;

		virtual int getColumnCount() const final;

		virtual ~BaseReportTextListView() = default;
	};
}
