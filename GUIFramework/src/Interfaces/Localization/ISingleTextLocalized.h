#pragma once

#include "ITextLocalized.h"

namespace gui_framework
{
	namespace interfaces
	{
		/// @brief Change localization of buttons, edit controls, etc.
		class GUI_FRAMEWORK_API ISingleTextLocalized : public ITextLocalized
		{
		private:
			std::string localizationKey;

		protected:
			virtual void updateLocalization(std::wstring_view localizedText) = 0;

		public:
			ISingleTextLocalized(bool autoUpdate = true);

			virtual void setLocalizationKey(std::string_view localizationKey) final;

			virtual void setLocalizationKey(std::string&& localizationKey) noexcept final;

			virtual const std::string& getLocalizationKey() const final;

			virtual bool updateLocalizationEvent() final override;

			virtual ~ISingleTextLocalized() = default;
		};
	}
}
