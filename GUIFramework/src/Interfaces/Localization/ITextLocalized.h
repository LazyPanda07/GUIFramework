#pragma once

#include "headers.h"

namespace gui_framework
{
	namespace interfaces
	{
		class GUI_FRAMEWORK_API ITextLocalized
		{
		private:
			bool autoUpdate;

		public:
			ITextLocalized(bool autoUpdate = true);

			virtual bool updateLocalizationEvent() = 0;
			
			virtual void setAutoUpdate(bool autoUpdate) final;
			
			virtual bool getAutoUpdate() const final;

			virtual ~ITextLocalized() = default;
		};
	}
}
