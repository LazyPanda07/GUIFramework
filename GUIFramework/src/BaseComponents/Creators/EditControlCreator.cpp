#include "headers.h"
#include "EditControlCreator.h"

#include "Components/EditControl.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* EditControlCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			EditControl* result = new EditControl(windowName, settings.x, settings.y, parent, settings.width, settings.height);

			try
			{
				result->setPlaceholder(any_cast<wstring>(additionalData));
			}
			catch (const std::exception&)
			{

			}

			return result;
		}
	}
}
