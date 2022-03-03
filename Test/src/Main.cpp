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

CREATE_DEFAULT_WINDOW_FUNCTION(window)

void standard()
{
	using namespace gui_framework;

	utility::ComponentSettings settings(300, 200, 800, 600);

	try
	{
		WindowHolder holder(make_unique<SeparateWindow>(L"MainWindow", L"Главное окно", settings, "main"));
		SeparateWindow* ptr = dynamic_cast<SeparateWindow*>(holder.get());
		Button* button = new Button(L"Create", L"Test", utility::ComponentSettings(0, 0, 200, 25), ptr);

		ptr->setExitMode(BaseComposite::exitMode::quit);

		ptr->setLargeIcon("assets/icon.ico");

		button->setOnClick([]()
			{
				thread([]()
					{
						utility::ComponentSettings settings(600, 400, 400, 200);

						WindowHolder holder(make_unique<SeparateWindow>(L"Window", L"Окно в другом потоке", settings, "window"));
						SeparateWindow* ptr = dynamic_cast<SeparateWindow*>(holder.get());
						Button* button = new Button(L"Create", L"Запустить в главном потоке", utility::ComponentSettings(0, 0, 200, 25), ptr);

						button->setOnClick([]()
							{
								GUIFramework::get().runOnUIThread([]()
									{
										cout << "Nice" << endl;
									});
							});

						holder.runMainLoop();
					}).detach();
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
		gui_framework::GUIFramework::initUIThreadId();
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
