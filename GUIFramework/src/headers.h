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
#include "JSONArrayWrapper.h"
#include "Exceptions/CantFindValueException.h"
#include "Exceptions/WrongEncodingException.h"
#include "ThreadPool.h"
#include "SingletonThreadPool.h"

#include "GUIFramework.h"

#pragma region AdditionalCreationData
#include "Utility/AdditionalCreationData/ButtonAdditionalCreationData.h"
#include "Utility/AdditionalCreationData/ChildWindowAdditionalCreationData.h"
#include "Utility/AdditionalCreationData/ComboBoxAdditionalCreationData.h"
#include "Utility/AdditionalCreationData/EditControlAdditionalCreationData.h"
#include "Utility/AdditionalCreationData/GroupBoxAdditionalCreationData.h"
#include "Utility/AdditionalCreationData/IconListViewAdditionalCreationData.h"
#include "Utility/AdditionalCreationData/ListBoxAdditionalCreationData.h"
#include "Utility/AdditionalCreationData/ProgressBarAdditionalCreationData.h"
#include "Utility/AdditionalCreationData/RichEditAdditionalCreationData.h"
#include "Utility/AdditionalCreationData/SeparateWindowAdditionalCreationData.h"
#include "Utility/AdditionalCreationData/StaticControlAdditionalCreationData.h"
#include "Utility/AdditionalCreationData/TabControlAdditionalCreationData.h"
#include "Utility/AdditionalCreationData/TextIconListViewAdditionalCreationData.h"
#include "Utility/AdditionalCreationData/TextListViewAdditionalCreationData.h"
#include "Utility/AdditionalCreationData/TrackbarControlAdditionalCreationData.h"
#pragma endregion

#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
