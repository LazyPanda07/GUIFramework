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

#include "BaseComponents/Creators/ListView/IconListViewCreator.h"
#include "BaseComponents/Creators/ListView/TextListViewCreator.h"
#include "BaseComponents/Creators/ListView/TextIconListViewCreator.h"
#include "BaseComponents/Creators/ListView/ListIconListViewCreator.h"
#include "BaseComponents/Creators/ListView/ListTextListViewCreator.h"
#include "BaseComponents/Creators/ListView/ListTextIconListViewCreator.h"

#include "Components/Button.h"
#include "Components/EditControl.h"
#include "Components/DropDownComboBox.h"
#include "Components/DropDownListComboBox.h"
#include "Components/SimpleComboBox.h"
#include "Components/ListBox.h"
#include "Components/MultipleSelectListBox.h"
#include "Components/RichEdit.h"
#include "Components/StaticControl.h"
#include "Composites/SeparateWindow.h"
#include "Composites/ChildWindow.h"
#include "Components/TabControl.h"
#include "Components/ProgressBar.h"
#include "Components/InfiniteProgressBar.h"
#include "Components/CheckBox.h"
#include "Components/GroupBox.h"

#include "Components/ListView/IconListView.h"
#include "Components/ListView/TextListView.h"
#include "Components/ListView/TextIconListView.h"
#include "Components/ListView/ListIconListView.h"
#include "Components/ListView/ListTextListView.h"
#include "Components/ListView/ListTextIconListView.h"

using namespace std;

namespace gui_framework
{
	void GUIFramework::initCreators()
	{
		creators[typeid(Button).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::ButtonCreator());

		creators[typeid(EditControl).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::EditControlCreator());

		creators[typeid(DropDownComboBox).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::DropDownComboBoxCreator());

		creators[typeid(DropDownListComboBox).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::DropDownListComboBoxCreator());

		creators[typeid(SimpleComboBox).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::SimpleComboBoxCreator());

		creators[typeid(ListBox).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::ListBoxCreator());

		creators[typeid(MultipleSelectListBox).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::MultipleSelectListBoxCreator());

		creators[typeid(RichEdit).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::RichEditCreator());

		creators[typeid(StaticControl).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::StaticControlCreator());

		creators[typeid(SeparateWindow).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::SeparateWindowCreator());

		creators[typeid(ChildWindow).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::ChildWindowCreator());

		creators[typeid(TabControl).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::TabControlCreator());

		creators[typeid(ProgressBar).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::ProgressBarCreator());

		creators[typeid(InfiniteProgressBar).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::InfiniteProgressBarCreator());

		creators[typeid(CheckBox).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::CheckBoxCreator());

		creators[typeid(GroupBox).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::GroupBoxCreator());

#pragma region ListViews
		creators[typeid(IconListView).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::IconListViewCreator());

		creators[typeid(ListIconListView).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::ListIconListViewCreator());

		creators[typeid(TextListView).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::TextListViewCreator());

		creators[typeid(ListTextListView).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::ListTextListViewCreator());

		creators[typeid(TextIconListView).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::TextIconListViewCreator());

		creators[typeid(ListTextIconListView).hash_code()] = unique_ptr<utility::BaseComponentCreator>(new utility::ListTextIconListViewCreator());
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
