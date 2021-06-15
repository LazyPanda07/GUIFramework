#include "pch.h"
#include "ButtonCreator.h"

#include "Components/Button.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* ButtonCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			auto[text, onClick] = any_cast<tuple<wstring, function<LRESULT(WPARAM, LPARAM)>>>(additionalData);

			return new Button(windowName, text, settings.x, settings.y, parent, onClick, settings.width, settings.height);
		}
	}
}
