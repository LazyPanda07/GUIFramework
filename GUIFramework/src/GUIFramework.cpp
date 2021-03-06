#include "headers.h"
#include "GUIFramework.h"

#include "Exceptions/GetLastErrorException.h"
#include "Exceptions/FileDoesNotExist.h"
#include "Exceptions/CantLoadModuleException.h"
#include "Exceptions/CantFindFunctionFromModuleException.h"

#include "Utility/Creators/Components/Buttons/ButtonCreator.h"
#include "Utility/Creators/Components/Buttons/CheckBoxCreator.h"
#include "Utility/Creators/Components/Buttons/ImageButtonCreator.h"

#include "Utility/Creators/Components/ListBoxes/ListBoxCreator.h"
#include "Utility/Creators/Components/ListBoxes/MultipleSelectListBoxCreator.h"

#include "Utility/Creators/Components/ProgressBars/ProgressBarCreator.h"
#include "Utility/Creators/Components/ProgressBars/InfiniteProgressBarCreator.h"

#include "Utility/Creators/Components/EditControlCreator.h"
#include "Utility/Creators/Components/RichEditCreator.h"
#include "Utility/Creators/Components/StaticControlCreator.h"
#include "Utility/Creators/Components/TabControlCreator.h"

#include "Utility/Creators/Components/ComboBoxes/DropDownComboBoxCreator.h"
#include "Utility/Creators/Components/ComboBoxes/DropDownListComboBoxCreator.h"
#include "Utility/Creators/Components/ComboBoxes/SimpleComboBoxCreator.h"

#include "Utility/Creators/Components/ListViews/IconListViewCreator.h"
#include "Utility/Creators/Components/ListViews/TextListViewCreator.h"
#include "Utility/Creators/Components/ListViews/TextIconListViewCreator.h"
#include "Utility/Creators/Components/ListViews/ListIconListViewCreator.h"
#include "Utility/Creators/Components/ListViews/ListTextListViewCreator.h"
#include "Utility/Creators/Components/ListViews/ListTextIconListViewCreator.h"

#include "Utility/Creators/Components/Trackbars/HorizontalTrackbarControlCreator.h"
#include "Utility/Creators/Components/Trackbars/VerticalTrackbarControlCreator.h"

#include "Utility/Creators/Composites/SeparateWindowCreator.h"
#include "Utility/Creators/Composites/ChildWindowCreator.h"
#include "Utility/Creators/Composites/GroupBoxCreator.h"

#include "Components/Buttons/Button.h"
#include "Components/Buttons/CheckBox.h"
#include "Components/Buttons/ImageButton.h"
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

#include "Deserialization/Deserializers/Composites/ChildWindowDeserializer.h"
#include "Deserialization/Deserializers/Composites/SeparateWindowDeserializer.h"
#include "Deserialization/Deserializers/Composites/GroupBoxDeserializer.h"

#include "Deserialization/Deserializers/Components/EditControlDeserializer.h"
#include "Deserialization/Deserializers/Components/RichEditDeserializer.h"
#include "Deserialization/Deserializers/Components/StaticControlDeserializer.h"
#include "Deserialization/Deserializers/Components/TabControlDeserializer.h"

#include "Deserialization/Deserializers/Components/Buttons/ButtonDeserializer.h"
#include "Deserialization/Deserializers/Components/Buttons/ImageButtonDeserializer.h"
#include "Deserialization/Deserializers/Components/Buttons/CheckBoxDeserializer.h"

#include "Deserialization/Deserializers/Components/ProgressBars/ProgressBarDeserializer.h"
#include "Deserialization/Deserializers/Components/ProgressBars/InfiniteProgressBarDeserializer.h"

#include "Deserialization/Deserializers/Components/Trackbars/HorizontalTrackbarControlDeserializer.h"
#include "Deserialization/Deserializers/Components/Trackbars/VerticalTrackbarControlDeserializer.h"

#include "Deserialization/Deserializers/Components/ComboBoxes/DropDownComboBoxDeserializer.h"
#include "Deserialization/Deserializers/Components/ComboBoxes/DropDownListComboBoxDeserializer.h"
#include "Deserialization/Deserializers/Components/ComboBoxes/SimpleComboBoxDeserializer.h"

#include "Deserialization/Deserializers/Components/ListBoxes/ListBoxDeserializer.h"
#include "Deserialization/Deserializers/Components/ListBoxes/MultipleSelectListBoxDeserializer.h"

#include "Deserialization/Deserializers/Components/ListViews/IconListViewDeserializer.h"
#include "Deserialization/Deserializers/Components/ListViews/ListIconListViewDeserializer.h"
#include "Deserialization/Deserializers/Components/ListViews/ListTextIconListViewDeserializer.h"
#include "Deserialization/Deserializers/Components/ListViews/ListTextListViewDeserializer.h"
#include "Deserialization/Deserializers/Components/ListViews/TextIconListViewDeserializer.h"
#include "Deserialization/Deserializers/Components/ListViews/TextListViewDeserializer.h"

#include "Interfaces/Localization/ITextLocalized.h"

#pragma warning(disable: 6335)

using namespace std;

template<>
struct hash<set<uint32_t>>
{
	size_t operator () (const set<uint32_t>& data);
};

static set<uint32_t> makeHotkey(uint32_t key, const vector<gui_framework::hotkeys::additionalKeys>& additionalKeys);

namespace gui_framework
{
	GUIFramework::hotkeyData::hotkeyData() :
		key(static_cast<uint32_t>(-1))
	{

	}

	GUIFramework::hotkeyData::hotkeyData(uint32_t key, const function<void()>& hotkeyEvent, const vector<hotkeys::additionalKeys>& additionalKeys) :
		key(key),
		hotkeyEvent(hotkeyEvent),
		additionalKeys(additionalKeys)
	{

	}

	GUIFramework::hotkeyData::hotkeyData(uint32_t key, const string& functionName, const string& moduleName, const vector<hotkeys::additionalKeys>& additionalKeys) :
		key(key),
		functionName(functionName),
		moduleName(moduleName),
		additionalKeys(additionalKeys)
	{

	}

	void GUIFramework::initCreators()
	{
		creators.reserve(25);

		this->addCreator<Button, utility::ButtonCreator>();

		this->addCreator<CheckBox, utility::CheckBoxCreator>();

		this->addCreator<ImageButton, utility::ImageButtonCreator>();

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

	void GUIFramework::initDeserializers()
	{
		deserializers.reserve(25);

		this->addDeserializer<Button, deserializers::ButtonDeserializer>();
		
		this->addDeserializer<CheckBox, deserializers::CheckBoxDeserializer>();
		
		this->addDeserializer<ImageButton, deserializers::ImageButtonDeserializer>();
		
		this->addDeserializer<EditControl, deserializers::EditControlDeserializer>();
		
		this->addDeserializer<RichEdit, deserializers::RichEditDeserializer>();
		
		this->addDeserializer<StaticControl, deserializers::StaticControlDeserializer>();

		this->addDeserializer<SeparateWindow, deserializers::SeparateWindowDeserializer>();

		this->addDeserializer<ChildWindow, deserializers::ChildWindowDeserializer>();

		this->addDeserializer<TabControl, deserializers::TabControlDeserializer>();
		
		this->addDeserializer<GroupBox, deserializers::GroupBoxDeserializer>();

#pragma region ProgressBars
		this->addDeserializer<ProgressBar, deserializers::ProgressBarDeserializer>();
		
		this->addDeserializer<InfiniteProgressBar, deserializers::InfiniteProgressBarDeserializer>();
#pragma endregion

#pragma region ComboBoxes
		this->addDeserializer<DropDownComboBox, deserializers::DropDownComboBoxDeserializer>();
		
		this->addDeserializer<DropDownListComboBox, deserializers::DropDownListComboBoxDeserializer>();
		
		this->addDeserializer<SimpleComboBox, deserializers::SimpleComboBoxDeserializer>();
#pragma endregion

#pragma region ListBoxes
		this->addDeserializer<ListBox, deserializers::ListBoxDeserializer>();
		
		this->addDeserializer<MultipleSelectListBox, deserializers::MultipleSelectListBoxDeserializer>();
#pragma endregion

#pragma region ListViews
		this->addDeserializer<IconListView, deserializers::IconListViewDeserializer>();
		
		this->addDeserializer<ListIconListView, deserializers::ListIconListViewDeserializer>();
		
		this->addDeserializer<TextListView, deserializers::TextListViewDeserializer>();
		
		this->addDeserializer<ListTextListView, deserializers::ListTextListViewDeserializer>();
		
		this->addDeserializer<TextIconListView, deserializers::TextIconListViewDeserializer>();
		
		this->addDeserializer<ListTextIconListView, deserializers::ListTextIconListViewDeserializer>();
#pragma endregion

#pragma region Trackbars
		this->addDeserializer<HorizontalTrackbarControl, deserializers::HorizontalTrackbarControlDeserializer>();
		
		this->addDeserializer<VerticalTrackbarControl, deserializers::VerticalTrackbarControlDeserializer>();
#pragma endregion
	}

	void GUIFramework::addComponent(BaseComponent* component)
	{
		unique_lock<recursive_mutex> lock(componentsMutex);

		components.push_back(component);
	}

	void GUIFramework::removeComponent(BaseComponent* component)
	{
		unique_lock<recursive_mutex> lock(componentsMutex);

		erase(components, component);
	}

	uint32_t GUIFramework::generateId(const wstring& windowName)
	{
		unique_lock<mutex> lock(idMutex);

		uint32_t id;

		if (availableIds.size())
		{
			id = availableIds.front();

			availableIds.pop();
		}
		else
		{
			id = nextId++;
		}

		generatedIds.insert(make_pair(windowName, id));

		return id;
	}

	void GUIFramework::removeIds(const wstring& windowName)
	{
		unique_lock<mutex> lock(idMutex);

		if (!generatedIds.contains(windowName))
		{
			return;
		}

		auto it = generatedIds.equal_range(windowName);

		for_each(it.first, it.second, [this](const pair<wstring, uint32_t>& data) { availableIds.push(generatedIds.extract(data.first).mapped()); });
	}

	void GUIFramework::removeId(const wstring& windowName, uint32_t id)
	{
		unique_lock<mutex> lock(idMutex);

		if (!generatedIds.contains(windowName))
		{
			return;
		}

		auto it = generatedIds.equal_range(windowName);

		for (; it.first != it.second; ++it.first)
		{
			if (it.first->second == id)
			{
				availableIds.push(generatedIds.extract(it.first).mapped());

				break;
			}
		}
	}

	vector<uint32_t> GUIFramework::getIds(const wstring& windowName)
	{
		unique_lock<mutex> lock(idMutex);

		auto resultIterator = generatedIds.equal_range(windowName);
		vector<uint32_t> result;

		if (resultIterator.first != generatedIds.end())
		{
			result.reserve(distance(resultIterator.first, resultIterator.second));

			for_each(resultIterator.first, resultIterator.second, [&result](const pair<wstring, uint32_t>& data) { result.push_back(data.second); });
		}

		return result;
	}

	void GUIFramework::processHotkeys() const
	{
		static set<const set<uint32_t>*> possibleHotkeys;
		static constexpr int keyDownBit = 1 << 16;

		possibleHotkeys.clear();

		ranges::for_each(allHotkeys, [](const set<uint32_t>& keys) { possibleHotkeys.insert(&keys); });

		for (const auto& i : allHotkeys)
		{
			for (const auto& j : i)
			{
				if (!(GetAsyncKeyState(j) & keyDownBit))
				{
					possibleHotkeys.erase(&i);

					break;
				}
			}
		}

		if (possibleHotkeys.size())
		{
			const set<uint32_t>& hotkey = **possibleHotkeys.begin();

			hotkeys.at(hash<set<uint32_t>>()(hotkey))();
		}
	}

	GUIFramework::GUIFramework() :
		nextId(1),
		modulesNeedToLoad(1),
		currentLoadedModules(modulesNeedToLoad)
	{
		if (!filesystem::exists(json_settings::settingsJSONFile))
		{
			throw runtime_error(format(R"(File "{}" does not exist)"sv, json_settings::settingsJSONFile));
		}

		jsonSettings = ifstream(json_settings::settingsJSONFile.data());

		try
		{
			int64_t threadsCount = jsonSettings.getInt(json_settings::threadsCountSetting);

			if (threadsCount != -1)
			{
				if (threadsCount)
				{
					threadPool = make_unique<threading::ThreadPool>(static_cast<uint32_t>(threadsCount));
				}
				else
				{
					threadPool = make_unique<threading::ThreadPool>();
				}
			}
		}
		catch (const json::exceptions::CantFindValueException&)
		{

		}

		InitCommonControlsEx(&comm);

		modules.insert({ "MSFT"s, LoadLibraryW(libraries::msftEditLibrary.data()) });

		const json::utility::jsonObject& settingsObject = jsonSettings.getObject(json_settings::settingsObject);

		try
		{
			if (settingsObject.getBool(json_settings::usingCreatorsSetting))
			{
				this->initCreators();
			}
		}
		catch (const json::exceptions::CantFindValueException&)
		{

		}

		try
		{
			if (settingsObject.getBool(json_settings::usingDeserializersSetting))
			{
				this->initDeserializers();
			}
		}
		catch (const json::exceptions::CantFindValueException&)
		{

		}

		try
		{
			const vector<json::utility::jsonObject>& jsonModules = settingsObject.getArray(json_settings::modulesSetting);

			modulesNeedToLoad += static_cast<int>(jsonModules.size());

			modules.reserve(modulesNeedToLoad);

			for (const auto& i : jsonModules)
			{
				const auto& moduleObject = std::get<json::utility::jsonObject>(i.data.front().second);
				const string& moduleName = moduleObject.getString(json_settings::moduleNameSetting);
				const auto& modulePath = find_if(moduleObject.data.begin(), moduleObject.data.end(),
					[](const pair<string, json::utility::jsonObject::variantType>& value) { return value.first == json_settings::pathToModuleSettings; })->second;
				string modulePathString;

				if (modulePath.index() == static_cast<size_t>(json::utility::variantTypeEnum::jString))
				{
					modulePathString = std::get<string>(modulePath);
				}

				{
					unique_lock<mutex> lock(loadModulesMutex);

					modules.insert({ moduleName, nullptr });

					modulesPaths.insert({ moduleName, ""s });
				}

				auto loadModule = [modulePathString, moduleName, this]()
				{
					try
					{
						if (modulePathString.empty())
						{
							if (!filesystem::exists(moduleName))
							{
								throw exceptions::FileDoesNotExist(moduleName, __FILE__, __FUNCTION__, __LINE__);
							}
						}
						else
						{
							if (!filesystem::exists(modulePathString))
							{
								throw exceptions::FileDoesNotExist(modulePathString, __FILE__, __FUNCTION__, __LINE__);
							}
						}
					}
					catch (const exceptions::FileDoesNotExist& e)
					{
						unique_lock<mutex> lock(loadModulesMutex);

						--modulesNeedToLoad;

						cantLoadedModules.push_back(e.what());

						return;
					}

					HMODULE module = LoadLibraryA
					(
						modulePathString.empty() ?
						moduleName.data() :
						modulePathString.data()
					);

					unique_lock<mutex> lock(loadModulesMutex);

					if (!module)
					{
						try
						{
							if (modulePathString.empty())
							{
								throw exceptions::CantLoadModuleException(moduleName, __FILE__, __FUNCTION__, __LINE__);
							}
							else
							{
								throw exceptions::CantLoadModuleException(modulePathString, __FILE__, __FUNCTION__, __LINE__);
							}
						}
						catch (const exceptions::CantLoadModuleException& e)
						{
							--modulesNeedToLoad;

							cantLoadedModules.push_back(e.what());
						}
					}
					else
					{
						modules[moduleName] = module;

						modulesPaths[moduleName] = modulePathString.empty() ? moduleName : modulePathString;

						++currentLoadedModules;
					}
				};

				this->addTask(loadModule);
			}
		}
		catch (const json::exceptions::CantFindValueException&)
		{

		}
	}

	GUIFramework::~GUIFramework()
	{
		for (auto& [name, module] : modules)
		{
			FreeLibrary(module);
		}
	}

	void GUIFramework::initUIThreadId()
	{
		GUIFramework::get().uiThreadId = GetCurrentThreadId();
	}

	void GUIFramework::runOnUIThread(const function<void()>& function)
	{
		GUIFramework& instance = GUIFramework::get();
		lock_guard<recursive_mutex> runOnUIThreadLock(instance.runOnUIThreadMutex);

		instance.runOnUIFunctions.push(function);
	}

	void GUIFramework::runOnUIThread(function<void()>&& function)
	{
		GUIFramework& instance = GUIFramework::get();
		lock_guard<recursive_mutex> runOnUIThreadLock(instance.runOnUIThreadMutex);

		instance.runOnUIFunctions.push(move(function));
	}

	void GUIFramework::restartApplication(int exitCode)
	{
		int argc = 0;
		wchar_t** argv = nullptr;
		wstring_view commandLine = GetCommandLineW();
		STARTUPINFO startInfo = {};
		PROCESS_INFORMATION processInfo = {};

		startInfo.cb = sizeof(startInfo);

		argv = CommandLineToArgvW(commandLine.data(), &argc);

		if (!CreateProcessW
		(
			argv[0],
			const_cast<wchar_t*>(commandLine.data()),
			nullptr,
			nullptr,
			false,
			NULL,
			nullptr,
			nullptr,
			&startInfo,
			&processInfo
		))
		{
			throw gui_framework::exceptions::GetLastErrorException(GetLastError(), __FILE__, __FUNCTION__, __LINE__);
		}

		exit(exitCode);
	}

	DWORD GUIFramework::getUIThreadId()
	{
		return GUIFramework::get().uiThreadId;
	}

	void GUIFramework::addTask(const function<void()>& task, const function<void()>& callback)
	{
		if (!threadPool)
		{
			throw runtime_error("Can't find threadsCount setting in gui_framework.json");
		}

		threadPool->addTask(task, callback);
	}

	void GUIFramework::addTask(function<void()>&& task, const function<void()>& callback)
	{
		if (!threadPool)
		{
			throw runtime_error("Can't find threadsCount setting in gui_framework.json");
		}

		threadPool->addTask(move(task), callback);
	}

	size_t GUIFramework::registerHotkey(uint32_t key, const function<void()>& onClick, const vector<hotkeys::additionalKeys>& additionalKeys)
	{
		set<uint32_t> hotkey = makeHotkey(key, additionalKeys);
		size_t id = hash<set<uint32_t>>()(hotkey);

		unique_lock<mutex> lock(hotkeyIdMutex);

		hotkeys[id] = onClick;

		allHotkeys.push_back(move(hotkey));

		serializableHotkeysData[id] = hotkeyData(key, onClick, additionalKeys);

		return id;
	}

	size_t GUIFramework::registerHotkey(uint32_t key, const string& functionName, const string& moduleName, const vector<hotkeys::additionalKeys>& additionalKeys)
	{
		onClickSignature tem = nullptr;

		{
			unique_lock<mutex> lock(loadModulesMutex);

			const HMODULE& module = this->getModules().at(moduleName);

			tem = reinterpret_cast<onClickSignature>(GetProcAddress(module, functionName.data()));

			if (!tem)
			{
				throw exceptions::CantFindFunctionFromModuleException(functionName, moduleName, __FILE__, __FUNCTION__, __LINE__);
			}
		}

		size_t id = this->registerHotkey(key, tem, additionalKeys);

		{
			unique_lock<mutex> lock(hotkeyIdMutex);

			serializableHotkeysData[id].functionName = functionName;
			serializableHotkeysData[id].moduleName = moduleName;
		}

		return id;
	}

	bool GUIFramework::unregisterHotkey(size_t hotkeyId)
	{
		unique_lock<mutex> lock(hotkeyIdMutex);

		auto it = hotkeys.find(hotkeyId);

		if (it != hotkeys.end())
		{
			set<uint32_t> hotkey = makeHotkey(serializableHotkeysData[hotkeyId].key, serializableHotkeysData[hotkeyId].additionalKeys);

			hotkeys.erase(it);

			erase(allHotkeys, hotkey);

			serializableHotkeysData.erase(hotkeyId);

			return true;
		}

		return false;
	}

	bool GUIFramework::unregisterHotkey(uint32_t key, const std::vector<hotkeys::additionalKeys>& additionalKeys)
	{
		unique_lock<mutex> lock(hotkeyIdMutex);

		set<uint32_t> hotkey = makeHotkey(key, additionalKeys);
		size_t hotkeyId = hash<set<uint32_t>>()(hotkey);
		auto it = hotkeys.find(hotkeyId);

		if (it != hotkeys.end())
		{
			hotkeys.erase(it);

			erase(allHotkeys, hotkey);

			serializableHotkeysData.erase(hotkeyId);

			return true;
		}

		return false;
	}

	vector<GUIFramework::hotkeyData> GUIFramework::getRegisteredHotkeys()
	{
		vector<hotkeyData> result;

		result.reserve(serializableHotkeysData.size());

		unique_lock<mutex> lock(hotkeyIdMutex);

		for (const auto& [key, value] : serializableHotkeysData)
		{
			result.emplace_back(value);
		}

		return result;
	}

	void GUIFramework::loadModule(const string& moduleName, const filesystem::path& pathToModule)
	{
		if (!filesystem::exists(pathToModule))
		{
			throw exceptions::FileDoesNotExist(moduleName, __FILE__, __FUNCTION__, __LINE__);
		}

		HMODULE	module = LoadLibraryA(pathToModule.string().data());

		if (!module)
		{
			throw exceptions::CantLoadModuleException(moduleName, __FILE__, __FUNCTION__, __LINE__);
		}

		modules.insert({ moduleName, module });
	}

	void GUIFramework::unloadModule(const string& moduleName)
	{
		auto it = modules.find(moduleName);

		if (it == modules.end())
		{
			return;
		}

		FreeLibrary(it->second);

		modules.erase(it);
	}

	BaseComponent* GUIFramework::findComponent(HWND handle)
	{
		unique_lock<recursive_mutex> lock(componentsMutex);

		auto it = ranges::find_if(components, [&handle](BaseComponent* component) { return component->getHandle() == handle; });

		return it == components.end() ? nullptr : *it;
	}

	BaseComponent* GUIFramework::findComponent(const wstring& componentName)
	{
		unique_lock<recursive_mutex> lock(componentsMutex);

		auto it = ranges::find_if(components, [&componentName](BaseComponent* component) { return component->getWindowName() == componentName; });

		return it == components.end() ? nullptr : *it;
	}

	bool GUIFramework::isExist(BaseComponent* component)
	{
		return ranges::find(components, component) != components.end();
	}

	vector<json::utility::jsonObject> GUIFramework::serializeHotkeys()
	{
		using json::utility::jsonObject;

		unique_lock<mutex> lock(hotkeyIdMutex);
		vector<jsonObject> result;

		for (const auto& [key, value] : serializableHotkeysData)
		{
			if (value.functionName.size())
			{
				jsonObject object;

				object.data.push_back({ "key"s, static_cast<uint64_t>(value.key) });
				object.data.push_back({ "functionName"s, value.functionName });
				object.data.push_back({ "moduleName"s, value.moduleName });
				object.data.push_back({ "pathToModule"s, modulesPaths.at(value.moduleName) });

				if (value.additionalKeys.size())
				{
					vector<jsonObject> additionalKeys;

					additionalKeys.reserve(value.additionalKeys.size());

					ranges::for_each(value.additionalKeys, [&additionalKeys](const hotkeys::additionalKeys& key) { json::utility::appendArray(static_cast<int64_t>(key), additionalKeys); });

					object.data.push_back({ "additionalKeys"s, move(additionalKeys) });
				}

				json::utility::appendArray(move(object), result);
			}
		}

		return result;
	}

	void GUIFramework::deserializeHotkeys(const json::utility::jsonObject& description)
	{
		using json::utility::jsonObject;

		const auto& jsonHotkeys = description.getArray("hotkeys");

		for (const auto& i : jsonHotkeys)
		{
			const jsonObject& hotkey = std::get<jsonObject>(i.data.front().second);

			uint32_t key = static_cast<uint32_t>(hotkey.getUnsignedInt("key"));
			const string& functionName = hotkey.getString("functionName");
			const string& moduleName = hotkey.getString("moduleName");
			vector<uint64_t> tem = json::utility::JSONArrayWrapper(hotkey.getArray("additionalKeys")).getAsUInt64_tArray();
			vector<hotkeys::additionalKeys> additionalKeys;

			ranges::for_each(tem, [&additionalKeys](uint64_t additionalKey) { additionalKeys.push_back(static_cast<hotkeys::additionalKeys>(additionalKey)); });

			this->registerHotkey(key, functionName, moduleName, additionalKeys);
		}
	}

	bool GUIFramework::isModulesLoaded() const
	{
		return modulesNeedToLoad == currentLoadedModules;
	}

	void GUIFramework::changeLocalization(const string& language) const
	{
		localization::TextLocalization::get().changeLanguage(language);
		localization::WTextLocalization::get().changeLanguage(language);

		for (const auto& component : components)
		{
			interfaces::ITextLocalized* localizable = dynamic_cast<interfaces::ITextLocalized*>(component);

			if (localizable && localizable->getAutoUpdate())
			{
				localizable->updateLocalizationEvent();
			}
		}
	}

	const unordered_map<size_t, smartPointerType<utility::BaseComponentCreator>>& GUIFramework::getCreators() const
	{
		return creators;
	}

	const unordered_map<size_t, smartPointerType<interfaces::IDeserializer>>& GUIFramework::getDeserializers() const
	{
		return deserializers;
	}

	const json::JSONParser& GUIFramework::getJSONSettings() const
	{
		return jsonSettings;
	}

	const unordered_map<string, HMODULE>& GUIFramework::getModules() const
	{
		return modules;
	}

	const unordered_map<string, string>& GUIFramework::getModulesPaths() const
	{
		return modulesPaths;
	}

	vector<string> GUIFramework::getCantLoadedModules()
	{
		unique_lock<mutex> lock(loadModulesMutex);

		return cantLoadedModules;
	}
}

size_t hash<set<uint32_t>>::operator () (const set<uint32_t>& data)
{
	if (data.empty())
	{
		return 0;
	}

	size_t result = 1;

	for (const auto& i : data)
	{
		result = 31 * result + i;
	}

	return result;
}

set<uint32_t> makeHotkey(uint32_t key, const vector<gui_framework::hotkeys::additionalKeys>& additionalKeys)
{
	set<uint32_t> hotkey;

	for_each(additionalKeys.begin(), additionalKeys.end(), [&hotkey](gui_framework::hotkeys::additionalKeys additionalKey) { hotkey.insert(static_cast<uint32_t>(additionalKey)); });

	hotkey.insert(key);

	return hotkey;
}
