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
			tuple<wstring, function<LRESULT(WPARAM, LPARAM)>> buttonData = any_cast<tuple<wstring, function<LRESULT(WPARAM, LPARAM)>>> (additionalData);

			return new Button(windowName, get<wstring>(buttonData), settings.x, settings.y, parent, get<function<LRESULT(WPARAM, LPARAM)>>(buttonData), settings.width, settings.height);
		}
	}
}
