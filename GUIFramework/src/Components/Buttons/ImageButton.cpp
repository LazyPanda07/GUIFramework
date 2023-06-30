#include "ImageButton.h"

#include "BaseComposites/BaseComposite.h"
#include "Styles/Components/Buttons/DefaultButtonStyles.h"
#include "Holders/LoadableHolders/BaseLoadableHolder.h"
#include "GUIFramework.h"

#pragma warning(disable: 6001)

using namespace std;

namespace gui_framework
{
	using imageType = utility::BaseLoadableHolder::imageType;

	void ImageButton::drawImage()
	{
		int resourceType;
		HANDLE imageHandle;
		function<HANDLE()> load;

		if (!pathToImage.empty())
		{
			load = [this]()
			{
				return LoadImageW(nullptr, pathToImage.wstring().data(), static_cast<uint32_t>(iType), imageWidth, imageHeight, LR_LOADFROMFILE);
			};
		}
		else if (imageResource)
		{
			load = [this]()
			{
				return LoadImageW(GUIFramework::get()[resourceModuleName], MAKEINTRESOURCE(imageResource), static_cast<uint32_t>(iType), imageWidth, imageHeight, NULL);
			};
		}
		else
		{
			return;
		}

		switch (iType)
		{
		case imageType::icon:
			utility::appendStyle(handle, BS_ICON);

			resourceType = IMAGE_ICON;

			break;
		case imageType::bitmap:
			utility::appendStyle(handle, BS_BITMAP);

			resourceType = IMAGE_BITMAP;

			break;

		default:
			break;
		}

		imageHandle = load();

		switch (iType)
		{
		case imageType::icon:
			image = static_cast<HICON>(imageHandle);

			break;
		case imageType::bitmap:
			image = static_cast<HBITMAP>(imageHandle);

			break;

		default:
			break;
		}

		switch (dType)
		{
		case gui_framework::ImageButton::drawingType::image:
			SendMessageW(handle, BM_SETIMAGE, resourceType, reinterpret_cast<LPARAM>(imageHandle));

			break;

		case gui_framework::ImageButton::drawingType::text:
			utility::removeStyle(handle, resourceType == IMAGE_ICON ? BS_ICON : BS_BITMAP);

			break;

		case gui_framework::ImageButton::drawingType::textAndImage:
			utility::removeStyle(handle, resourceType == IMAGE_ICON ? BS_ICON : BS_BITMAP);

			SendMessageW(handle, BM_SETIMAGE, resourceType, reinterpret_cast<LPARAM>(imageHandle));

			break;

		default:
			break;
		}
	}

	ImageButton::ImageButton(const wstring& buttonName, const filesystem::path& pathToImage, drawingType dType, imageType iType, uint16_t imageWidth, uint16_t imageHeight, const utility::ComponentSettings& settings, BaseComposite* parent, const function<void()>& onClick) :
		BaseButton
		(
			buttonName,
			L"",
			settings,
			styles::DefaultButtonStyles(),
			parent,
			onClick
		),
		IResizableComponent
		(
			handle,
			parent->getHandle()
		),
		pathToImage(pathToImage),
		dType(dType),
		iType(iType),
		imageWidth(imageWidth),
		imageHeight(imageHeight)
	{
		this->drawImage();
	}

	ImageButton::ImageButton(const wstring& buttonName, const filesystem::path& pathToImage, drawingType dType, imageType iType, uint16_t imageWidth, uint16_t imageHeight, const utility::ComponentSettings& settings, BaseComposite* parent, const string& functionName, const string& moduleName) :
		BaseButton
		(
			buttonName,
			L"",
			settings,
			styles::DefaultButtonStyles(),
			parent,
			functionName,
			moduleName
		),
		IResizableComponent
		(
			handle,
			parent->getHandle()
		),
		pathToImage(pathToImage),
		dType(dType),
		iType(iType),
		imageWidth(imageWidth),
		imageHeight(imageHeight)
	{
		this->drawImage();
	}

	ImageButton::ImageButton(const wstring& buttonName, uint32_t imageResources, drawingType dType, imageType iType, uint16_t imageWidth, uint16_t imageHeight, const utility::ComponentSettings& settings, BaseComposite* parent, const function<void()>& onClick, const string& resourceModuleName) :
		BaseButton
		(
			buttonName,
			L"",
			settings,
			styles::DefaultButtonStyles(),
			parent,
			onClick
		),
		IResizableComponent
		(
			handle,
			parent->getHandle()
		),
		imageResource(imageResource),
		resourceModuleName(resourceModuleName),
		dType(dType),
		iType(iType),
		imageWidth(imageWidth),
		imageHeight(imageHeight)
	{
		this->drawImage();
	}

	ImageButton::ImageButton(const wstring& buttonName, uint32_t imageResources, drawingType dType, imageType iType, uint16_t imageWidth, uint16_t imageHeight, const utility::ComponentSettings& settings, BaseComposite* parent, const string& functionName, const string& moduleName, const string& resourceModuleName) :
		BaseButton
		(
			buttonName,
			L"",
			settings,
			styles::DefaultButtonStyles(),
			parent,
			functionName,
			moduleName
		),
		IResizableComponent
		(
			handle,
			parent->getHandle()
		),
		imageResource(imageResource),
		resourceModuleName(resourceModuleName),
		dType(dType),
		iType(iType),
		imageWidth(imageWidth),
		imageHeight(imageHeight)
	{
		this->drawImage();
	}

	void ImageButton::setImage(const filesystem::path& pathToImage, drawingType dType, imageType iType, uint16_t imageWidth, uint16_t imageHeight)
	{
		this->pathToImage = pathToImage;
		this->dType = dType;
		this->iType = iType;
		this->imageWidth = imageWidth;
		this->imageHeight = imageHeight;

		resourceModuleName.clear();
		imageResource = NULL;

		this->drawImage();
	}

	void ImageButton::setImage(uint32_t imageResource, drawingType dType, imageType iType, uint16_t imageWidth, uint16_t imageHeight, const string& resourceModuleName)
	{
		this->imageResource = imageResource;
		this->resourceModuleName = resourceModuleName;
		this->dType = dType;
		this->iType = iType;
		this->imageWidth = imageWidth;
		this->imageHeight = imageHeight;

		pathToImage.clear();

		this->drawImage();
	}

	const filesystem::path& ImageButton::getPathToImage() const
	{
		return pathToImage;
	}

	uint16_t ImageButton::getImageWidth() const
	{
		return imageWidth;
	}

	uint16_t ImageButton::getImageHeight() const
	{
		return imageHeight;
	}

	ImageButton::drawingType ImageButton::getDrawingType() const
	{
		return dType;
	}

	ImageButton::imageType ImageButton::getImageType() const
	{
		return iType;
	}

	size_t ImageButton::getHash() const
	{
		return typeid(ImageButton).hash_code();
	}

	json::JSONBuilder ImageButton::getStructure() const
	{
		using json::utility::jsonObject;

		json::JSONBuilder builder = BaseButton::getStructure();
		jsonObject& current = get<jsonObject>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		current.setUnsignedInt("imageWidth"s, static_cast<uint64_t>(imageWidth));
		current.setUnsignedInt("imageHeight"s, static_cast<uint64_t>(imageHeight));

		current.setString("pathToImage", utility::getStringFromRawPath(pathToImage));
		current.setString("resourceModuleName", resourceModuleName);

		current.setUnsignedInt("drawingType"s, static_cast<uint64_t>(dType));
		current.setUnsignedInt("imageType"s, static_cast<uint64_t>(iType));
		current.setUnsignedInt("imageResource", imageResource);

		return builder;
	}

	ImageButton::~ImageButton()
	{
		try
		{
			DeleteObject(any_cast<HBITMAP>(image));
		}
		catch (const bad_any_cast&)
		{
			DeleteObject(any_cast<HICON>(image));
		}
	}
}
