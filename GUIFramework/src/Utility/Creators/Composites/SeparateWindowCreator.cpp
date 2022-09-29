#include "core.h"
#include "SeparateWindowCreator.h"

#include "Composites/SeparateWindow.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* SeparateWindowCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			auto [className, functionName] = any_cast<tuple<wstring, string>>(additionalData);

			return new SeparateWindow(className, windowName, settings, functionName);
		}
	}
}
