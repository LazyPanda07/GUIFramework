#include "pch.h"
#include "BaseWindow.h"

#include "Exceptions/FileDoesNotExist.h"

#include "Utility/Holders/LoadableHolders/CursorsHolder.h"
#include "Utility/Holders/LoadableHolders/ImagesHolder.h"
#include "Utility/Holders/LoadableHolders/IconsHolder.h"

using namespace std;

namespace gui_framework
{
	BaseWindow::drawedImages::drawedImages(smartPointerType<utility::BaseLoadableHolder>&& images, utility::BaseLoadableHolder::imageType type) noexcept :
		images(move(images)),
		type(type)
	{

	}

	void BaseWindow::drawedImages::addImage(BaseWindow* owner, int x, int y, const filesystem::path& pathToImage)
	{
		uint16_t index = images->addImage(pathToImage);

		coordinates.insert({ index, {x, y} });
	}

	void BaseWindow::drawedImages::removeImage(const filesystem::path& pathToImage)
	{
		uint16_t index = images->getImageIndex(pathToImage);

		images->removeImage(index);

		coordinates.erase(index);
	}

	BaseWindow::BaseWindow(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, const interfaces::IStyles& styles, BaseComponent* parent, const string& windowFunctionName) :
		BaseComposite
		(
			className,
			windowName,
			settings,
			styles,
			parent,
			windowFunctionName
		)
	{

	}

	void BaseWindow::initDrawing(const string& pictureBlockName, uint16_t imagesWidth, uint16_t imagesHeight, utility::BaseLoadableHolder::imageType type)
	{
		smartPointerType<utility::BaseLoadableHolder> images;

		switch (type)
		{
		case utility::BaseLoadableHolder::imageType::bitmap:
			images = utility::make_smart_pointer<utility::ImagesHolder>(imagesWidth, imagesHeight);

			break;
		case utility::BaseLoadableHolder::imageType::icon:
			images = utility::make_smart_pointer<utility::IconsHolder>(imagesWidth, imagesHeight);

			break;
		case utility::BaseLoadableHolder::imageType::cursor:
			throw runtime_error("Wrong type value");

			break;
		default:
			break;
		}

		pictures.try_emplace(pictureBlockName, move(images), type);
	}

	void BaseWindow::addImage(const string& pictureBlockName, int x, int y, const filesystem::path& pathToImage)
	{
		drawedImages& images = pictures.at(pictureBlockName);

		if (!filesystem::exists(pathToImage))
		{
			throw exceptions::FileDoesNotExist(pathToImage);
		}

		images.addImage(this, x, y, pathToImage);

		this->drawAllImages();
	}

	void BaseWindow::removeImage(const string& pictureBlockName, const filesystem::path& pathToImage)
	{
		drawedImages& images = pictures.at(pictureBlockName);

		images.removeImage(pathToImage);

		this->drawAllImages();
	}

	void BaseWindow::drawAllImages()
	{
		InvalidateRect(handle, nullptr, true);

		PAINTSTRUCT paint = {};
		HDC deviceContext = BeginPaint(handle, &paint);
		LPARAM drawData = NULL;
		
		for (const auto& [picturesBlockName, data] : pictures)
		{
			uint32_t flags = DSS_NORMAL;
			uint16_t width = data.images->getImagesWidth();
			uint16_t height = data.images->getImagesHeight();

			for (const auto& [index, coordinates] : data.coordinates)
			{
				switch (data.type)
				{
				case utility::BaseLoadableHolder::imageType::bitmap:
					drawData = reinterpret_cast<LPARAM>(dynamic_cast<utility::ImagesHolder*>(data.images.get())->getImage(index));

					flags |= DST_BITMAP;

					break;
				case utility::BaseLoadableHolder::imageType::icon:
					drawData = reinterpret_cast<LPARAM>(dynamic_cast<utility::IconsHolder*>(data.images.get())->getIcon(index));

					flags |= DST_ICON;

					break;

				default:
					break;
				}

				DrawStateW(deviceContext, NULL, nullptr, drawData, NULL, coordinates.first, coordinates.second, width, height, flags);
			}
		}

		ReleaseDC(handle, deviceContext);

		EndPaint(handle, &paint);
	}

	void BaseWindow::setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		BaseComposite::setBackgroundColor(red, green, blue);

		this->drawAllImages();
	}

	json::JSONBuilder BaseWindow::getStructure() const
	{
		using json::utility::objectSmartPointer;
		using json::utility::jsonObject;

		if (pictures.empty())
		{
			return BaseComposite::getStructure();
		}

		json::JSONBuilder builder = BaseComposite::getStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		for (const auto& [pictureBlockName, data] : pictures)
		{
			string imageHolderName = pictureBlockName + "ImageHolder";
			vector<objectSmartPointer<jsonObject>> jsonCoordinates;

			data.images->loadBaseLoadableHolderStructure(current);

			auto& lastImageHolder = current->data.back();

			lastImageHolder.first = imageHolderName;

			for (const auto& [index, coordinates] : data.coordinates)
			{
				objectSmartPointer<jsonObject> object = json::utility::make_object<jsonObject>();

				object->data.push_back({ "x"s, static_cast<int64_t>(coordinates.first) });
				object->data.push_back({ "y"s, static_cast<int64_t>(coordinates.second) });

				json::utility::appendArray(move(object), jsonCoordinates);
			}

			get<objectSmartPointer<jsonObject>>(lastImageHolder.second)->data.push_back({ "coordinates"s, move(jsonCoordinates) });
		}

		return builder;
	}
}
