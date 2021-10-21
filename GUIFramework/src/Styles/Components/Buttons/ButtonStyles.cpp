#include "headers.h"
#include "ButtonStyles.h"

using namespace std;

namespace gui_framework
{
	namespace styles
	{
		ButtonStyles::ButtonStyles(const ButtonStyles& buttonStyles)
		{
			this->appendStyle(buttonStyles.getStyles());
			
			this->appendExtendedStyle(buttonStyles.getExtendedStyles());
		}
	}
}
