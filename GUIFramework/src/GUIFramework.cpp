#include "pch.h"
#include "GUIFramework.h"

#include "BaseComponents/FactoryMethod/ButtonCreator.h"
#include "BaseComponents/FactoryMethod/EditControlCreator.h"
#include "BaseComponents/FactoryMethod/DropDownComboBoxCreator.h"
#include "BaseComponents/FactoryMethod/DropDownListComboBoxCreator.h"
#include "BaseComponents/FactoryMethod/SimpleComboBoxCreator.h"
#include "BaseComponents/FactoryMethod/ListBoxCreator.h"
#include "BaseComponents/FactoryMethod/MultipleSelectListBoxCreator.h"
#include "BaseComponents/FactoryMethod/RichEditCreator.h"
#include "BaseComponents/FactoryMethod/StaticControlCreator.h"

#include "Components/Button.h"
#include "Components/EditControl.h"
#include "Components/DropDownComboBox.h"
#include "Components/DropDownListComboBox.h"
#include "Components/SimpleComboBox.h"
#include "Components/ListBox.h"
#include "Components/MultipleSelectListBox.h"
#include "Components/RichEdit.h"
#include "Components/StaticControl.h"

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
	}

	GUIFramework::GUIFramework() :
		jsonSettings(ifstream(settings::settingsJSONFile.data())),
		threadPool(static_cast<uint32_t>(jsonSettings.get<int64_t>(settings::threadsCountSetting))),
		msftEditModule(LoadLibraryW(libraries::msftEditLibrary.data())),
		nextHMENU(0)
	{
		InitCommonControlsEx(&comm);

		this->initCreators();
	}

	GUIFramework::~GUIFramework()
	{
		FreeLibrary(msftEditModule);
	}

	GUIFramework& GUIFramework::get()
	{
		static GUIFramework instance;

		return instance;
	}

	void GUIFramework::addTask(const function<void()>& task, const function<void()>& callback)
	{
		threadPool.addTask(task, callback);
	}

	void GUIFramework::addTask(function<void()>&& task, const function<void()>& callback)
	{
		threadPool.addTask(move(task), callback);
	}

	uint64_t GUIFramework::generateHMENU(const wstring& windowName)
	{
		uint64_t hmenu = nextHMENU++;

		autoGeneratedHMENUs.insert(make_pair(windowName, hmenu));

		return hmenu;
	}

	void GUIFramework::removeHMENUs(const wstring& windowName)
	{
		autoGeneratedHMENUs.erase(windowName);
	}

	void GUIFramework::removeHMENU(const wstring& windowName, uint64_t hmenu)
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

	vector<uint64_t> GUIFramework::getHMENUs(const wstring& windowName)
	{
		auto resultIterator = autoGeneratedHMENUs.equal_range(windowName);
		vector<uint64_t> result;

		if (resultIterator.first != autoGeneratedHMENUs.end())
		{
			result.reserve(distance(resultIterator.first, resultIterator.second));

			for_each(resultIterator.first, resultIterator.second, [&result](const pair<wstring, uint64_t>& data) { result.push_back(data.second); });
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
