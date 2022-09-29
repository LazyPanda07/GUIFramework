#include "ImageButton.h"

#include "BaseComposites/BaseComposite.h"
#include "Styles/Components/Buttons/DefaultButtonStyles.h"
#include "Utility/Holders/LoadableHolders/BaseLoadableHolder.h"

using namespace std;

namespace gui_framework
{
	void ImageButton::drawImage()
	{
		if (!pathToImage.empty())
		{
			int imageType;
			HANDLE imageHandle;

			if (pathToImage.extension() == ".ico")
			{
				utility::appendStyle(handle, BS_ICON);

				imageHandle = LoadImageW(nullptr, pathToImage.wstring().data(), static_cast<uint32_t>(utility::BaseLoadableHolder::imageType::icon), imageWidth, imageHeight, LR_LOADFROMFILE);

				image = static_cast<HICON>(imageHandle);

				imageType = IMAGE_ICON;
			}
			else
			{
				utility::appendStyle(handle, BS_BITMAP);

				imageHandle = LoadImageW(nullptr, pathToImage.wstring().data(), static_cast<uint32_t>(utility::BaseLoadableHolder::imageType::bitmap), imageWidth, imageHeight, LR_LOADFROMFILE);

				image = static_cast<HBITMAP>(imageHandle);

				imageType = IMAGE_BITMAP;
			}

			switch (type)
			{
			case gui_framework::ImageButton::drawingType::image:
				SendMessageW(handle, BM_SETIMAGE, imageType, reinterpret_cast<LPARAM>(imageHandle));

				break;

			case gui_framework::ImageButton::drawingType::text:
				utility::removeStyle(handle, imageType == IMAGE_ICON ? BS_ICON : BS_BITMAP);

				break;

			case gui_framework::ImageButton::drawingType::textAndImage:
				utility::removeStyle(handle, imageType == IMAGE_ICON ? BS_ICON : BS_BITMAP);

				SendMessageW(handle, BM_SETIMAGE, imageType, reinterpret_cast<LPARAM>(imageHandle));

				break;

			default:
				break;
			}
		}
	}

	ImageButton::ImageButton(const wstring& buttonName, const filesystem::path& pathToImage, drawingType type, uint16_t imageWidth, uint16_t imageHeight, const utility::ComponentSettings& settings, BaseComposite* parent, const function<void()>& onClick) :
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
		imageWidth(imageWidth),
		imageHeight(imageHeight),
		type(type)
	{
		this->drawImage();
	}

	ImageButton::ImageButton(const wstring& buttonName, const filesystem::path& pathToImage, drawingType type, uint16_t imageWidth, uint16_t imageHeight, const utility::ComponentSettings& settings, BaseComposite* parent, const string& functionName, const string& moduleName) :
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
		imageWidth(imageWidth),
		imageHeight(imageHeight),
		type(type)
	{
		this->drawImage();
	}

	void ImageButton::setImage(const filesystem::path& pathToImage, drawingType type, uint16_t imageWidth, uint16_t imageHeight)
	{
		this->pathToImage = pathToImage;
		this->type = type;
		this->imageWidth = imageWidth;
		this->imageHeight = imageHeight;

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
		return type;
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

		current.data.push_back({ "imageWidth"s, static_cast<uint64_t>(imageWidth) });
		current.data.push_back({ "imageHeight"s, static_cast<uint64_t>(imageHeight) });

		current.data.push_back({ "pathToImage"s, utility::getStringFromRawPath(pathToImage) });

		current.data.push_back({ "drawingType"s, static_cast<uint64_t>(type) });

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
