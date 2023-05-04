#pragma once

#include "Core.h"

namespace gui_framework
{
	namespace interfaces
	{
		/// @brief Provides changing localization in component by calling GUIFramework::changeLocalization
		///
		/// Doesn't change components windows names
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
