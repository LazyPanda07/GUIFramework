#include "IMultipleTextLocalized.h"

using namespace std;

namespace gui_framework
{
	namespace interfaces
	{
		IMultipleTextLocalized::IMultipleTextLocalized(bool autoUpdate) :
			ITextLocalized(autoUpdate)
		{

		}

		void IMultipleTextLocalized::addLocalizationKey(size_t index, const string& localizationKey)
		{
			localizationKeys[index] = localizationKey;
		}

		void IMultipleTextLocalized::addLocalizationKey(size_t index, string&& localizationKey) noexcept
		{
			localizationKeys[index] = move(localizationKey);
		}

		void IMultipleTextLocalized::removeLocalizationKey(size_t index)
		{
			localizationKeys.erase(index);
		}

		void IMultipleTextLocalized::removeLocalizationKey(const string& localizationKey)
		{
			erase_if(localizationKeys, [&localizationKey](const auto& key) { return key.second == localizationKey; });
		}

		const unordered_map<size_t, string>& IMultipleTextLocalized::getLocalizationKeys() const
		{
			return localizationKeys;
		}

		bool IMultipleTextLocalized::updateLocalizationEvent()
		{
			localization::WTextLocalization& textLocalization = localization::WTextLocalization::get();

			for (const auto& [index, localizationKey] : localizationKeys)
			{
				this->updateLocalization(index, textLocalization[localizationKey]);
			}

			return localizationKeys.size();
		}
	}
}
