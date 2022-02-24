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

		void IMultipleTextLocalized::addLocalizationKey(const string& localizationKey)
		{
			if (ranges::find(localizationKeys, localizationKey) != localizationKeys.end())
			{
				return;
			}

			localizationKeys.push_back(localizationKey);
		}

		void IMultipleTextLocalized::addLocalizationKey(string&& localizationKey) noexcept
		{
			if (ranges::find(localizationKeys, localizationKey) != localizationKeys.end())
			{
				return;
			}

			localizationKeys.push_back(move(localizationKey));
		}

		void IMultipleTextLocalized::insertLocalizationKey(size_t index, const string& localizationKey)
		{
			if (ranges::find(localizationKeys, localizationKey) != localizationKeys.end())
			{
				return;
			}

			localizationKeys.insert(localizationKeys.begin() + index, localizationKey);
		}

		void IMultipleTextLocalized::insertLocalizationKey(size_t index, string&& localizationKey) noexcept
		{
			if (ranges::find(localizationKeys, localizationKey) != localizationKeys.end())
			{
				return;
			}

			localizationKeys.insert(localizationKeys.begin() + index, move(localizationKey));
		}

		void IMultipleTextLocalized::removeLocalizationKey(size_t index)
		{
			localizationKeys.erase(localizationKeys.begin() + index);
		}

		void IMultipleTextLocalized::removeLocalizationKey(const string& localizationKey)
		{
			erase(localizationKeys, localizationKey);
		}

		const vector<string>& IMultipleTextLocalized::getLocalizationKeys() const
		{
			return localizationKeys;
		}

		bool IMultipleTextLocalized::updateLocalizationEvent()
		{
			localization::WTextLocalization& textLocalization = localization::WTextLocalization::get();

			for (size_t i = 0; i < localizationKeys.size(); i++)
			{
				this->updateLocalization(i, textLocalization[localizationKeys[i]]);
			}

			return localizationKeys.size();
		}
	}
}
