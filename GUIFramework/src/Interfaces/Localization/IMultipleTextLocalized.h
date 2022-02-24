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
			virtual void updateLocalization(size_t index, const std::wstring& localizedText) = 0;

		public:
			IMultipleTextLocalized(bool autoUpdate = true);

			virtual void addLocalizationKey(const std::string& localizationKey) final;

			virtual void addLocalizationKey(std::string&& localizationKey) noexcept final;

			virtual void insertLocalizationKey(size_t index, const std::string& localizationKey) final;

			virtual void insertLocalizationKey(size_t index, std::string&& localizationKey) noexcept final;

			virtual void removeLocalizationKey(size_t index) final;

			virtual void removeLocalizationKey(const std::string& localizationKey) final;

			virtual const std::vector<std::string>& getLocalizationKeys() const final;

			virtual bool updateLocalizationEvent() final override;

			virtual ~IMultipleTextLocalized() = default;
		};
	}
}
