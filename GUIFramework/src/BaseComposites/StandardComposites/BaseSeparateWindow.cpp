#include "headers.h"
#include "BaseSeparateWindow.h"

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
		largeIcon(nullptr),
		smallIcon(nullptr),
		onClose([]() { return true; })
	{

	}

	void BaseSeparateWindow::setLargeIcon(const filesystem::path& pathToLargeIcon)
	{
		if (!filesystem::exists(pathToLargeIcon))
		{
			throw exceptions::FileDoesNotExist(pathToLargeIcon);
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
			throw exceptions::FileDoesNotExist(pathToSmallIcon);
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

	void BaseSeparateWindow::setOnClose(const function<bool()>& onClose)
	{
		this->onClose = onClose;

		onCloseFunctionName.clear();
		onCloseFunctionModuleName.clear();
	}

	void BaseSeparateWindow::setOnClose(const string& onCloseFunctionName, const string& onCloseFunctionModuleName)
	{
		GUIFramework& instance = GUIFramework::get();
		const HMODULE& module = instance.getModules().at(onCloseFunctionModuleName);

		onCloseSignature tem = reinterpret_cast<onCloseSignature>(GetProcAddress(module, onCloseFunctionName.data()));

		if (!tem)
		{
			throw exceptions::CantFindFunctionFromModuleException(onCloseFunctionName, onCloseFunctionModuleName);
		}

		onClose = tem;

		this->onCloseFunctionName = onCloseFunctionName;
		this->onCloseFunctionModuleName = onCloseFunctionModuleName;
	}

	const function<bool()>& BaseSeparateWindow::getOnClose() const
	{
		return onClose;
	}

	json::JSONBuilder BaseSeparateWindow::getStructure() const
	{
		using json::utility::jsonObject;
		using json::utility::objectSmartPointer;

		json::JSONBuilder builder = BaseWindow::getStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		if (!pathToSmallIcon.empty())
		{
			current->data.push_back({ "pathToSmallIcon"s, utility::getStringFromRawPath(pathToSmallIcon) });
		}

		if (!pathToLargeIcon.empty())
		{
			current->data.push_back({ "pathToLargeIcon"s, utility::getStringFromRawPath(pathToLargeIcon) });
		}

		if (onCloseFunctionName.size())
		{
			current->data.push_back({ "onCloseFunctionName"s, onCloseFunctionName });
			current->data.push_back({ "onCloseFunctionModuleName"s, onCloseFunctionModuleName });
		}

		return builder;
	}

	BaseSeparateWindow::~BaseSeparateWindow()
	{
		DestroyIcon(largeIcon);
		DestroyIcon(smallIcon);
	}
}
