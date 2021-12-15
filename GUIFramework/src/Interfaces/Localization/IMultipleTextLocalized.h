#pragma once

#include "ITextLocalized.h"

namespace gui_framework
{
	namespace interfaces
	{
		class GUI_FRAMEWORK_API IMultipleTextLocalized : public ITextLocalized
		{
		private:
			std::unordered_map<size_t, std::string> localizationKeys;

		protected:
			virtual void updateLocalization(size_t index, const std::wstring& localizedText) = 0;

		public:
			IMultipleTextLocalized(bool autoUpdate = true);

			virtual void addLocalizationKey(size_t index, const std::string& localizationKey) final;

			virtual void addLocalizationKey(size_t index, std::string&& localizationKey) noexcept final;

			virtual void removeLocalizationKey(size_t index) final;

			virtual void removeLocalizationKey(const std::string& localizationKey) final;

			virtual const std::unordered_map<size_t, std::string>& getLocalizationKeys() const final;

			virtual bool updateLocalizationEvent() final override;

			virtual ~IMultipleTextLocalized() = default;
		};
	}
}
