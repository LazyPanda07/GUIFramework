#include "core.h"
#include "ChildWindowCreator.h"

#include "Composites/ChildWindow.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* ChildWindowCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			auto [className, functionName] = any_cast<tuple<wstring, string>>(additionalData);

			return new ChildWindow(className, windowName, settings, parent, functionName);
		}
	}
}
