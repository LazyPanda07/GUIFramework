#include "StaticControlCreator.h"

#include "Components/StaticControl.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* StaticControlCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComposite* parent)
		{
			return new StaticControl(windowName, any_cast<wstring>(additionalData), settings, parent);
		}
	}
}
