#include "ITextLocalized.h"

using namespace std;

namespace gui_framework
{
	namespace interfaces
	{
		ITextLocalized::ITextLocalized(bool autoUpdate) :
			autoUpdate(autoUpdate)
		{

		}
		
		void ITextLocalized::setAutoUpdate(bool autoUpdate)
		{
			this->autoUpdate = autoUpdate;
		}
		
		bool ITextLocalized::getAutoUpdate() const
		{
			return autoUpdate;
		}
	}
}
