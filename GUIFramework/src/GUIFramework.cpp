#include "pch.h"
#include "GUIFramework.h"

#include "BaseComponents/Creators/ButtonCreator.h"
#include "BaseComponents/Creators/EditControlCreator.h"
#include "BaseComponents/Creators/DropDownComboBoxCreator.h"
#include "BaseComponents/Creators/DropDownListComboBoxCreator.h"
#include "BaseComponents/Creators/SimpleComboBoxCreator.h"
#include "BaseComponents/Creators/ListBoxCreator.h"
#include "BaseComponents/Creators/MultipleSelectListBoxCreator.h"
#include "BaseComponents/Creators/RichEditCreator.h"
#include "BaseComponents/Creators/StaticControlCreator.h"
#include "BaseComponents/Creators/SeparateWindowCreator.h"
#include "BaseComponents/Creators/ChildWindowCreator.h"
#include "BaseComponents/Creators/TabControlCreator.h"
#include "BaseComponents/Creators/ProgressBarCreator.h"
#include "BaseComponents/Creators/InfiniteProgressBarCreator.h"
#include "BaseComponents/Creators/CheckBoxCreator.h"
#include "BaseComponents/Creators/GroupBoxCreator.h"

#include "BaseComponents/Creators/ListViews/IconListViewCreator.h"
#include "BaseComponents/Creators/ListViews/TextListViewCreator.h"
#include "BaseComponents/Creators/ListViews/TextIconListViewCreator.h"
#include "BaseComponents/Creators/ListViews/ListIconListViewCreator.h"
#include "BaseComponents/Creators/ListViews/ListTextListViewCreator.h"
#include "BaseComponents/Creators/ListViews/ListTextIconListViewCreator.h"

#include "BaseComponents/Creators/Trackbars/HorizontalTrackbarControlCreator.h"
#include "BaseComponents/Creators/Trackbars/VerticalTrackbarControlCreator.h"

#include "Components/Buttons/Button.h"
#include "Components/Buttons/CheckBox.h"
#include "Components/EditControl.h"
#include "Components/ComboBoxes/DropDownComboBox.h"
#include "Components/ComboBoxes/DropDownListComboBox.h"
#include "Components/ComboBoxes/SimpleComboBox.h"
#include "Components/ListBoxes/ListBox.h"
#include "Components/ListBoxes/MultipleSelectListBox.h"
#include "Components/RichEdit.h"
#include "Components/StaticControl.h"
#include "Components/TabControl.h"
#include "Components/ProgressBars/ProgressBar.h"
#include "Components/ProgressBars/InfiniteProgressBar.h"
#include "Composites/SeparateWindow.h"
#include "Composites/ChildWindow.h"
#include "Composites/GroupBox.h"

#include "Components/ListViews/IconListView.h"
#include "Components/ListViews/TextListView.h"
#include "Components/ListViews/TextIconListView.h"
#include "Components/ListViews/ListIconListView.h"
#include "Components/ListViews/ListTextListView.h"
#include "Components/ListViews/ListTextIconListView.h"

#include "Components/Trackbars/HorizontalTrackbarControl.h"
#include "Components/Trackbars/VerticalTrackbarControl.h"

using namespace std;

namespace gui_framework
{
	void GUIFramework::initCreators()
	{
		creators[typeid(Button).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::ButtonCreator());

		creators[typeid(CheckBox).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::CheckBoxCreator());

		creators[typeid(EditControl).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::EditControlCreator());

		creators[typeid(RichEdit).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::RichEditCreator());

		creators[typeid(StaticControl).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::StaticControlCreator());

		creators[typeid(SeparateWindow).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::SeparateWindowCreator());

		creators[typeid(ChildWindow).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::ChildWindowCreator());

		creators[typeid(TabControl).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::TabControlCreator());

		creators[typeid(GroupBox).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::GroupBoxCreator());

#pragma region ProgressBars
		creators[typeid(ProgressBar).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::ProgressBarCreator());

		creators[typeid(InfiniteProgressBar).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::InfiniteProgressBarCreator());
#pragma endregion

#pragma region ComboBoxes
		creators[typeid(DropDownComboBox).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::DropDownComboBoxCreator());

		creators[typeid(DropDownListComboBox).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::DropDownListComboBoxCreator());

		creators[typeid(SimpleComboBox).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::SimpleComboBoxCreator());
#pragma endregion

#pragma region ListBoxes
		creators[typeid(ListBox).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::ListBoxCreator());

		creators[typeid(MultipleSelectListBox).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::MultipleSelectListBoxCreator());
#pragma endregion

#pragma region ListViews
		creators[typeid(IconListView).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::IconListViewCreator());

		creators[typeid(ListIconListView).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::ListIconListViewCreator());

		creators[typeid(TextListView).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::TextListViewCreator());

		creators[typeid(ListTextListView).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::ListTextListViewCreator());

		creators[typeid(TextIconListView).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::TextIconListViewCreator());

		creators[typeid(ListTextIconListView).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::ListTextIconListViewCreator());
#pragma endregion

#pragma region Trackbars
		creators[typeid(HorizontalTrackbarControl).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::HorizontalTrackbarControlCreator());

		creators[typeid(VerticalTrackbarControl).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::VerticalTrackbarControlCreator());
#pragma endregion
	}

	GUIFramework::GUIFramework() :
		jsonSettings(ifstream(settings::settingsJSONFile.data())),
		threadPool(static_cast<uint32_t>(jsonSettings.get<int64_t>(settings::threadsCountSetting))),
		msftEditModule(LoadLibraryW(libraries::msftEditLibrary.data())),
		nextHMENU(1)
	{
		InitCommonControlsEx(&comm);

		try
		{
			if (jsonSettings.get<bool>("usingDefaultCreators"))
			{
				this->initCreators();
			}
		}
		catch (const json::exceptions::CantFindValueException&)
		{

		}
	}

	GUIFramework::~GUIFramework()
	{
		FreeLibrary(msftEditModule);
	}

	void GUIFramework::addTask(const function<void()>& task, const function<void()>& callback)
	{
		threadPool.addTask(task, callback);
	}

	void GUIFramework::addTask(function<void()>&& task, const function<void()>& callback)
	{
		threadPool.addTask(move(task), callback);
	}

	uint32_t GUIFramework::generateHMENU(const wstring& windowName)
	{
		uint32_t hmenu = nextHMENU++;

		autoGeneratedHMENUs.insert(make_pair(windowName, hmenu));

		return hmenu;
	}

	void GUIFramework::removeHMENUs(const wstring& windowName)
	{
		autoGeneratedHMENUs.erase(windowName);
	}

	void GUIFramework::removeHMENU(const wstring& windowName, uint32_t hmenu)
	{
		auto it = autoGeneratedHMENUs.equal_range(windowName);

		for (; it.first != it.second; ++it.first)
		{
			if (it.first->second == hmenu)
			{
				autoGeneratedHMENUs.erase(it.first);

				break;
			}
		}
	}

	void GUIFramework::addCreator(size_t hash, unique_ptr<utility::BaseComponentCreator>&& creator)
	{
		creators[hash] = move(creator);
	}

	vector<uint32_t> GUIFramework::getHMENUs(const wstring& windowName)
	{
		auto resultIterator = autoGeneratedHMENUs.equal_range(windowName);
		vector<uint32_t> result;

		if (resultIterator.first != autoGeneratedHMENUs.end())
		{
			result.reserve(distance(resultIterator.first, resultIterator.second));

			for_each(resultIterator.first, resultIterator.second, [&result](const pair<wstring, uint32_t>& data) { result.push_back(data.second); });
		}

		return result;
	}

	const json::JSONParser& GUIFramework::getJSONSettings() const
	{
		return jsonSettings;
	}

	const unordered_map<size_t, unique_ptr<utility::BaseComponentCreator>>& GUIFramework::getCreators() const
	{
		return creators;
	}
}
