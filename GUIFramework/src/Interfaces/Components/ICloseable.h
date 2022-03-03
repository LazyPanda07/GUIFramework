#pragma once

#include "headers.h"

namespace gui_framework
{
	namespace interfaces
	{
		class GUI_FRAMEWORK_API ICloseable
		{
		protected:
			HWND closeableHandle;
			std::function<bool()> onClose;
			std::string onCloseFunctionName;
			std::string onCloseFunctionModuleName;

		public:
			ICloseable(HWND closeableHandle);

			bool close(int exitCode);

			virtual void setOnClose(const std::function<bool()>& onClose) final;

			/// @brief Load function from module. Can be seriazlied
			/// @param onCloseFunctionName 
			/// @param onCloseFunctionModuleName 
			/// @exception CantFindFunctionFromModuleException 
			/// @exception std::out_of_range Can't find moduleName in loaded modules
			virtual void setOnClose(const std::string& onCloseFunctionName, const std::string& onCloseFunctionModuleName) final;

			virtual const std::function<bool()>& getOnClose() const final;

			virtual ~ICloseable() = default;
		};
	}
}
