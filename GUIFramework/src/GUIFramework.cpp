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
		creators.reserve(24);

		this->addCreator<Button, utility::ButtonCreator>();

		this->addCreator<CheckBox, utility::CheckBoxCreator>();

		this->addCreator<EditControl, utility::EditControlCreator>();

		this->addCreator<RichEdit, utility::RichEditCreator>();

		this->addCreator<StaticControl, utility::StaticControlCreator>();

		this->addCreator<SeparateWindow, utility::SeparateWindowCreator>();

		this->addCreator<ChildWindow, utility::ChildWindowCreator>();

		this->addCreator<TabControl, utility::TabControlCreator>();

		this->addCreator<GroupBox, utility::GroupBoxCreator>();

#pragma region ProgressBars
		this->addCreator<ProgressBar, utility::ProgressBarCreator>();

		this->addCreator<InfiniteProgressBar, utility::InfiniteProgressBarCreator>();
#pragma endregion

#pragma region ComboBoxes
		this->addCreator<DropDownComboBox, utility::DropDownComboBoxCreator>();

		this->addCreator<DropDownListComboBox, utility::DropDownListComboBoxCreator>();

		this->addCreator<SimpleComboBox, utility::SimpleComboBoxCreator>();
#pragma endregion

#pragma region ListBoxes
		this->addCreator<ListBox, utility::ListBoxCreator>();

		this->addCreator<MultipleSelectListBox, utility::MultipleSelectListBoxCreator>();
#pragma endregion

#pragma region ListViews
		this->addCreator<IconListView, utility::IconListViewCreator>();

		this->addCreator<ListIconListView, utility::ListIconListViewCreator>();

		this->addCreator<TextListView, utility::TextListViewCreator>();

		this->addCreator<ListTextListView, utility::ListTextListViewCreator>();

		this->addCreator<TextIconListView, utility::TextIconListViewCreator>();

		this->addCreator<ListTextIconListView, utility::ListTextIconListViewCreator>();
#pragma endregion

#pragma region Trackbars
		this->addCreator<HorizontalTrackbarControl, utility::HorizontalTrackbarControlCreator>();

		this->addCreator<VerticalTrackbarControl, utility::VerticalTrackbarControlCreator>();
#pragma endregion
	}

	GUIFramework::GUIFramework() :
		jsonSettings(ifstream(settings::settingsJSONFile.data())),
		threadPool(static_cast<uint32_t>(jsonSettings.get<int64_t>(settings::threadsCountSetting))),
		msftEditModule(LoadLibraryW(libraries::msftEditLibrary.data())),
		nextId(1)
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

	uint32_t GUIFramework::generateId(const wstring& windowName)
	{
		unique_lock<mutex> lock(idMutex);

		uint32_t HMENU;

		if (availableIds.size())
		{
			HMENU = availableIds.front();

			availableIds.pop();
		}
		else
		{
			HMENU = nextId++;
		}

		autoGeneratedIds.insert(make_pair(windowName, HMENU));

		return HMENU;
	}

	void GUIFramework::removeIds(const wstring& windowName)
	{
		unique_lock<mutex> lock(idMutex);

		if (!autoGeneratedIds.contains(windowName))
		{
			return;
		}

		auto it = autoGeneratedIds.equal_range(windowName);

		for_each(it.first, it.second, [this](const pair<wstring, uint32_t>& data) { availableIds.push(autoGeneratedIds.extract(data.first).mapped()); });
	}

	void GUIFramework::removeId(const wstring& windowName, uint32_t id)
	{
		unique_lock<mutex> lock(idMutex);

		if (!autoGeneratedIds.contains(windowName))
		{
			return;
		}

		auto it = autoGeneratedIds.equal_range(windowName);

		for (; it.first != it.second; ++it.first)
		{
			if (it.first->second == id)
			{
				availableIds.push(autoGeneratedIds.extract(it.first).mapped());

				break;
			}
		}
	}

	vector<uint32_t> GUIFramework::getIds(const wstring& windowName)
	{
		auto resultIterator = autoGeneratedIds.equal_range(windowName);
		vector<uint32_t> result;

		if (resultIterator.first != autoGeneratedIds.end())
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
