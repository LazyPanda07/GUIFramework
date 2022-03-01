#include "headers.h"
#include "BaseDialogBox.h"

#include "GUIFramework.h"
#include "Styles/Composites/DialogBoxStyles.h"
#include "Utility//Holders/WindowHolder.h"

using namespace std;

namespace gui_framework
{
	BaseDialogBox::messageBoxResponse BaseDialogBox::createMessageBox(const wstring& text, const wstring& title, messageBoxType type, BaseComponent* parent, bool helpButton)
	{
		return static_cast<messageBoxResponse>(MessageBoxW(parent ? parent->getHandle() : nullptr, text.data(), title.data(), static_cast<UINT>(type) | (helpButton ? MB_HELP : NULL)));
	}

	BaseDialogBox::BaseDialogBox(const wstring& className, const wstring& title, const utility::ComponentSettings& settings, const string& dialogBoxFunctionName, const string& moduleName, uint16_t smallIconResource, uint16_t largeIconResource) :
		BaseComposite
		(
			className,
			title,
			settings,
			styles::DialogBoxStyles(),
			nullptr,
			dialogBoxFunctionName,
			moduleName,
			smallIconResource,
			largeIconResource
		),
		IComponentVisibility(handle),
		ICloseable(handle),
		isShowDialogUsed(false)
	{
		this->hide();
	}

	int BaseDialogBox::showDialog()
	{
		GUIFramework& instance = GUIFramework::get();
		lock_guard<mutex> lock(instance.componentsMutex);
		WindowHolder holder(this);

		isShowDialogUsed = true;

		this->show();

		for (const auto& component : instance.components)
		{
			if (component != this)
			{
				EnableWindow(component->getHandle(), false);
			}
		}

		return holder.runMainLoop();
	}

	BaseDialogBox::~BaseDialogBox()
	{
		if (isShowDialogUsed)
		{
			GUIFramework& instance = GUIFramework::get();
			lock_guard<mutex> lock(instance.componentsMutex);

			for (const auto& component : instance.components)
			{
				if (component != this)
				{
					EnableWindow(component->getHandle(), true);
				}
			}
		}
	}
}
