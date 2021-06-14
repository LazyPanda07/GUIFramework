#include <iostream>

#include "GUIFramework.h"
#include "Composites/SeparateWindow.h"
#include "Composites/DialogBox.h"
#include "Composites/AdditionalCreationData/ButtonAdditionalCreationData.h"
#include "Components/Button.h"

#pragma comment (lib, "GUIFramework.lib")

using namespace std;

void test(const wstring& className, const wstring& title, const string& functionName, int x, int y)
{
	using namespace gui_framework;

	utility::ComponentSettings settings(WS_BORDER, x, y, 800, 600);

	unique_ptr<SeparateWindow> mainWindow(make_unique<SeparateWindow>(className, title, settings, functionName));
	DialogBox::DialogBoxBuilder builder(L"TestDialog", L"DialogTitle", 300, 300);
	auto onClick = [](WPARAM, LPARAM) -> LRESULT
	{
		cout << "WOW" << endl;

		return 0;
	};

	builder.addDialogBoxFunction("child");

	builder.addComponent<Button>(L"Button", 200, 20, DialogBox::DialogBoxBuilder::alignment::left, utility::AdditionalCreationData<Button>(L"Текст", onClick));

	unique_ptr<DialogBox> dialog(builder.build());

	dialog->show();

	MSG msg = {};

	while (GetMessageW(&msg, nullptr, NULL, NULL))
	{
		TranslateMessage(&msg);

		DispatchMessageW(&msg);
	}
}

CREATE_DEFAULT_WINDOW_FUNCTION(main)

CREATE_DEFAULT_WINDOW_FUNCTION(child)

int main(int argc, char** argv)
{
	setlocale(LC_CTYPE, "RU");

	gui_framework::GUIFramework::get();

	thread(test, L"Main window", L"Title", "main", 300, 200).detach();

	string s;

	while (cin >> s)
	{

	}




	return 0;
}
