#include <iostream>

#include "GUIFramework.h"
#include "Utility/Holders/WindowHolder.h"
#include "MenuItems/MenuItem.h"
#include "MenuItems/DropDownMenuItem.h"
#include "ComponentsHeader.h"
#include "CompositesHeader.h"
#include "AdditionalCreationDataHeader.h"

#pragma comment (lib, "GUIFramework.lib")

using namespace std;

CREATE_DEFAULT_WINDOW_FUNCTION(main)

CREATE_DEFAULT_WINDOW_FUNCTION(dialog)

void standard()
{
	using namespace gui_framework;

	utility::ComponentSettings settings(300, 200, 800, 600);

	try
	{
		WindowHolder holder(make_unique<SeparateWindow>(L"MainWindow", L"Главное окно", settings, "main"));
		SeparateWindow* ptr = dynamic_cast<SeparateWindow*>(holder.get());
		Button* button = new Button(L"Create", L"Create dialog", utility::ComponentSettings(0, 0, 200, 20), ptr);
		
		ptr->setExitMode(BaseComposite::exitMode::quit);
		
		ptr->setLargeIcon(R"(assets\icon.ico)");

		button->setOnClick([]()
			{
				DialogBox::DialogBoxBuilder builder(L"Rofl", L"Name", 400, 400, "dialog");

				builder.addComponent<Button>(L"Button", 200, 20, DialogBox::DialogBoxBuilder::alignment::center);

				DialogBox* dialog = builder.build();
				Button* button = dynamic_cast<Button*>(dialog->findChild(L"Button"));

				button->setText(L"Close");

				button->setOnClick([dialog]()
					{
						dialog->close(10);
					});

				cout << dialog->showDialog() << endl;

				cout << "Rofel" << endl;
			});

		holder.runMainLoop();
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
}

int main(int argc, char** argv)
{
	try
	{
		gui_framework::GUIFramework::get();
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;

		return 0;
	}

	SetConsoleOutputCP(CP_UTF8);

	standard();

	return 0;
}
