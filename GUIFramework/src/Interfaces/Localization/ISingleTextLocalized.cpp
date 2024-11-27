#include "ISingleTextLocalized.h"

using namespace std;

namespace gui_framework
{
	namespace interfaces
	{
		ISingleTextLocalized::ISingleTextLocalized(bool autoUpdate) :
			ITextLocalized(autoUpdate)
		{

		}

		void ISingleTextLocalized::setLocalizationKey(string_view localizationKey)
		{
			this->localizationKey = localizationKey;
		}

		void ISingleTextLocalized::setLocalizationKey(string&& localizationKey) noexcept
		{
			this->localizationKey = move(localizationKey);
		}

		const string& ISingleTextLocalized::getLocalizationKey() const
		{
			return localizationKey;
		}

		bool ISingleTextLocalized::updateLocalizationEvent()
		{
			if (localizationKey.size())
			{
				this->updateLocalization(localization::WTextLocalization::get()[localizationKey]);

				return true;
			}

			return false;
		}
	}
}
