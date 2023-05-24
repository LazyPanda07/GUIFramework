#pragma once

#include "SeparateWindowParser.h"
#include "BaseComposites/StandardComposites/BaseMainWindow.h"

namespace gui_framework
{
	namespace parsers
	{
		/// @brief Parse MainWindowParser specific properties
		struct GUI_FRAMEWORK_API MainWindowParser : public SeparateWindowParser
		{
			uint16_t trayIconResource;
			std::vector<std::pair<std::wstring, BaseMainWindow::Function>> items;

		public:
			MainWindowParser();

			void parse(const json::utility::jsonObject& description) override;

			~MainWindowParser() = default;
		};
	}
}
