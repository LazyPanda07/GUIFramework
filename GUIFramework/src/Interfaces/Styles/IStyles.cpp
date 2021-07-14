#include "pch.h"
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
