#include "BaseSeparateWindow.h"

#include "GUIFramework.h"

#include "Styles/Composites/SeparateWindowStyles.h"
#include "Exceptions/CantFindFunctionFromModuleException.h"
#include "Exceptions/FileDoesNotExist.h"

using namespace std;

namespace gui_framework
{
	BaseSeparateWindow::BaseSeparateWindow(const wstring& className, const wstring& titleName, const utility::ComponentSettings& settings, const string& windowFunctionName, bool maximize, bool minimize, const string& moduleName, uint16_t smallIconResource, uint16_t largeIconResource) :
		BaseWindow
		(
			className,
			titleName,
			settings,
			styles::SeparateWindowStyles(maximize, minimize),
			nullptr,
			windowFunctionName,
			moduleName,
			smallIconResource,
			largeIconResource
		),
		ICloseable(handle),
		IResizableComponent
		(
			handle,
			nullptr
		),
		largeIcon(nullptr),
		smallIcon(nullptr)
	{

	}

	void BaseSeparateWindow::enableResize()
	{
		gui_framework::utility::appendStyle(handle, WS_MAXIMIZEBOX);

		gui_framework::utility::appendStyle(handle, WS_THICKFRAME);
	}

	void BaseSeparateWindow::disableResize()
	{
		gui_framework::utility::removeStyle(handle, WS_MAXIMIZEBOX);

		gui_framework::utility::removeStyle(handle, WS_THICKFRAME);
	}

	void BaseSeparateWindow::setLargeIcon(const filesystem::path& pathToLargeIcon)
	{
		if (!filesystem::exists(pathToLargeIcon))
		{
			throw exceptions::FileDoesNotExist(pathToLargeIcon, __FILE__, __FUNCTION__, __LINE__);
		}

		this->pathToLargeIcon = pathToLargeIcon;

		if (largeIcon)
		{
			DestroyIcon(largeIcon);

			largeIcon = nullptr;
		}

		largeIcon = static_cast<HICON>(LoadImageW(nullptr, pathToLargeIcon.wstring().data(), IMAGE_ICON, standard_sizes::largeIconWidth, standard_sizes::largeIconHeight, LR_LOADFROMFILE));

		SendMessageW(handle, WM_SETICON, ICON_BIG, reinterpret_cast<LPARAM>(largeIcon));
	}

	void BaseSeparateWindow::setSmallIcon(const filesystem::path& pathToSmallIcon)
	{
		if (!filesystem::exists(pathToSmallIcon))
		{
			throw exceptions::FileDoesNotExist(pathToSmallIcon, __FILE__, __FUNCTION__, __LINE__);
		}

		this->pathToSmallIcon = pathToSmallIcon;

		if (smallIcon)
		{
			DestroyIcon(smallIcon);

			smallIcon = nullptr;
		}

		smallIcon = static_cast<HICON>(LoadImageW(nullptr, pathToSmallIcon.wstring().data(), IMAGE_ICON, standard_sizes::smallIconWidth, standard_sizes::smallIconHeight, LR_LOADFROMFILE));

		SendMessageW(handle, WM_SETICON, ICON_SMALL, reinterpret_cast<LPARAM>(smallIcon));
	}

	json::JSONBuilder BaseSeparateWindow::getStructure() const
	{
		using json::utility::jsonObject;

		json::JSONBuilder builder = BaseWindow::getStructure();
		jsonObject& current = get<jsonObject>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		if (!pathToSmallIcon.empty())
		{
			current.data.push_back({ "pathToSmallIcon"s, utility::getStringFromRawPath(pathToSmallIcon) });
		}

		if (!pathToLargeIcon.empty())
		{
			current.data.push_back({ "pathToLargeIcon"s, utility::getStringFromRawPath(pathToLargeIcon) });
		}

		if (onCloseFunctionName.size())
		{
			current.data.push_back({ "onCloseFunctionName"s, onCloseFunctionName });
			current.data.push_back({ "onCloseFunctionModuleName"s, onCloseFunctionModuleName });
		}

		return builder;
	}

	BaseSeparateWindow::~BaseSeparateWindow()
	{
		DestroyIcon(largeIcon);
		DestroyIcon(smallIcon);
	}
}
