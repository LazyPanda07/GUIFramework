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

#include <Windows.h>
#include <CommCtrl.h>

#include "WindowMessages.h"
#include "Constants.h"
#include "Utility/ComponentSettings.h"
#include "Utility/Utility.h"

// #include "JSONUtility.h"
// #include "JSONParser.h"
// #include "JSONBuilder.h"

#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
