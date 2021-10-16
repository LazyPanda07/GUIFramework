#include "headers.h"
#include "IStyles.h"

using namespace std;

namespace gui_framework
{
	namespace interfaces
	{
		void IStyles::appendStyle(LONG_PTR style)
		{
			styles |= style;
		}

		void IStyles::appendExtendedStyle(LONG_PTR extendedStyle)
		{
			extendedStyles |= extendedStyle;
		}

		IStyles::IStyles() :
			styles(NULL),
			extendedStyles(NULL)
		{
			
		}

		IStyles::IStyles(LONG_PTR styles, LONG_PTR extendedStyles) :
			styles(styles),
			extendedStyles(extendedStyles)
		{

		}

		LONG_PTR IStyles::getStyles() const
		{
			return styles;
		}

		LONG_PTR IStyles::getExtendedStyles() const
		{
			return extendedStyles;
		}
	}
}
