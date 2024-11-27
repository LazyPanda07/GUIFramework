#pragma once

#include "ITextLocalized.h"

namespace gui_framework
{
	namespace interfaces
	{
		/// @brief Change localization of combo boxes, list views, tab controls, etc.
		class GUI_FRAMEWORK_API IMultipleTextLocalized : public ITextLocalized
		{
		private:
			std::vector<std::string> localizationKeys;

		protected:
			virtual void updateLocalization(size_t index, std::wstring_view localizedText) = 0;

		public:
			IMultipleTextLocalized(bool autoUpdate = true);

			void addLocalizationKey(std::string_view localizationKey);

			void insertLocalizationKey(size_t index, const std::string& localizationKey);

			void insertLocalizationKey(size_t index, std::string&& localizationKey) noexcept;

			void removeLocalizationKey(size_t index);

			void removeLocalizationKey(std::string_view localizationKey);

			const std::vector<std::string>& getLocalizationKeys() const;

			virtual bool updateLocalizationEvent() final override;

			virtual ~IMultipleTextLocalized() = default;
		};
	}
}
