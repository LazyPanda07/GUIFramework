#include "pch.h"
#include "CheckBoxCreator.h"

#include "Components/CheckBox.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* CheckBoxCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			auto [text, onCheck, onClear, onClick] = any_cast<tuple<wstring, function<LRESULT(WPARAM, LPARAM)>, function<LRESULT(WPARAM, LPARAM)>, function<LRESULT(WPARAM, LPARAM)>>>(additionalData);

			return new CheckBox(windowName, text, settings.x, settings.y, parent, onCheck, onClear, onClick, settings.width, settings.height);
		}
	}
}
