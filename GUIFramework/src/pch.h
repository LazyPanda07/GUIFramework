#pragma once

#include <format>
#include <chrono>
#include <algorithm>
#include <memory>
#include <cstdint>
#include <stdexcept>
#include <functional>
#include <fstream>
#include <sstream>
#include <concepts>
#include <any>
#include <filesystem>
#include <ranges>

#include <atomic>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <shared_mutex>

#include <vector>
#include <array>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>

#include <Windows.h>
#include <CommCtrl.h>
#include <Richedit.h>
#include <uxtheme.h>

#include "WindowMessages.h"
#include "GUIFrameworkConstants.h"
#include "Utility/ComponentSettings.h"
#include "Utility/Utility.h"

#include "JSONUtility.h"
#include "JSONParser.h"
#include "JSONBuilder.h"
#include "Exceptions/CantFindValueException.h"
#include "Exceptions/WrongEncodingException.h"
#include "ThreadPool.h"
#include "SingletonThreadPool.h"

#include "GUIFramework.h"

#pragma region AdditionalCreationData
#include "Composites/AdditionalCreationData/ButtonAdditionalCreationData.h"
#include "Composites/AdditionalCreationData/ChildWindowAdditionalCreationData.h"
#include "Composites/AdditionalCreationData/ComboBoxAdditionalCreationData.h"
#include "Composites/AdditionalCreationData/EditControlAdditionalCreationData.h"
#include "Composites/AdditionalCreationData/GroupBoxAdditionalCreationData.h"
#include "Composites/AdditionalCreationData/IconListViewAdditionalCreationData.h"
#include "Composites/AdditionalCreationData/ListBoxAdditionalCreationData.h"
#include "Composites/AdditionalCreationData/ProgressBarAdditionalCreationData.h"
#include "Composites/AdditionalCreationData/RichEditAdditionalCreationData.h"
#include "Composites/AdditionalCreationData/SeparateWindowAdditionalCreationData.h"
#include "Composites/AdditionalCreationData/StaticControlAdditionalCreationData.h"
#include "Composites/AdditionalCreationData/TabControlAdditionalCreationData.h"
#include "Composites/AdditionalCreationData/TextIconListViewAdditionalCreationData.h"
#include "Composites/AdditionalCreationData/TextListViewAdditionalCreationData.h"
#include "Composites/AdditionalCreationData/TrackbarControlAdditionalCreationData.h"
#pragma endregion

#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
