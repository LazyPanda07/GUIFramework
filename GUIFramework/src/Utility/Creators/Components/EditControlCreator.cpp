#include "core.h"
#include "EditControlCreator.h"

#include "Components/EditControl.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* EditControlCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			EditControl* result = new EditControl(windowName, settings, parent);

			try
			{
				result->setPlaceholder(any_cast<wstring>(additionalData));
			}
			catch (const exception&)
			{

			}

			return result;
		}
	}
}
