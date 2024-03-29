#include "BaseDialogBox.h"

#include "GUIFramework.h"
#include "Styles/Composites/DialogBoxStyles.h"
#include "Holders/WindowHolder.h"

using namespace std;

namespace gui_framework
{
	BaseDialogBox::messageBoxResponse BaseDialogBox::createMessageBox(const wstring& text, const wstring& title, messageBoxType type, BaseComposite* parent, bool helpButton)
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
		isShowDialogUsed(false),
		windowWithUserFocus(nullptr)
	{
		this->hide();

		this->setExitMode(exitMode::quit);
	}

	int BaseDialogBox::showDialog()
	{
		GUIFramework& instance = GUIFramework::get();
		unique_lock<recursive_mutex> lock(instance.componentsMutex);
		WindowHolder holder(this);

		isShowDialogUsed = true;

		windowWithUserFocus = GetFocus();

		this->show();

		for (const auto& component : instance.components)
		{
			if (component == this)
			{
				break;
			}
			else if (dynamic_cast<BaseComposite*>(component))
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
			unique_lock<recursive_mutex> lock(instance.componentsMutex);

			for (const auto& component : instance.components)
			{
				if (component == this)
				{
					break;
				}
				else if (dynamic_cast<BaseComposite*>(component))
				{
					EnableWindow(component->getHandle(), true);
				}
			}

			SetFocus(windowWithUserFocus);
		}
	}
}
