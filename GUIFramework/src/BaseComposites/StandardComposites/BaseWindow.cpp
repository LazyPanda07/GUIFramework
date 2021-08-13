#include "pch.h"
#include "BaseWindow.h"

#include "Exceptions/FileDoesNotExist.h"

#include "Utility/Paint/Draw.h"

using namespace std;

namespace gui_framework
{
	void BaseWindow::drawedImages::init(uint16_t imagesWidth, uint16_t imagesHeight)
	{
		images = make_unique<utility::ImagesHolder>(imagesWidth, imagesHeight);
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

	void BaseWindow::initDrawing(uint16_t imagesWidth, uint16_t imagesHeight)
	{
		pictures.init(imagesWidth, imagesHeight);
	}

	void BaseWindow::addImage(int x, int y, const filesystem::path& pathToImage)
	{
		if (!pictures.images)
		{
			throw runtime_error("Call initDrawing before calling addImage");
		}

		if (!filesystem::exists(pathToImage))
		{
			throw exceptions::FileDoesNotExist(pathToImage);
		}

		pictures.addImage(this, x, y, pathToImage);

		this->drawAllImages();
	}

	void BaseWindow::removeImage(const filesystem::path& pathToImage)
	{
		if (!pictures.images)
		{
			throw runtime_error("Call initDrawing before calling removeImage");
		}

		pictures.removeImage(pathToImage);

		InvalidateRect(handle, nullptr, true);

		this->drawAllImages();
	}

	void BaseWindow::drawAllImages()
	{
		if (!pictures.images)
		{
			return;
		}

		PAINTSTRUCT paint = {};
		HDC deviceContext = BeginPaint(handle, &paint);
		LPARAM drawData = NULL;
		uint32_t flags = DSS_NORMAL | DST_BITMAP;
		uint16_t width = pictures.images->getImagesWidth();
		uint16_t height = pictures.images->getImagesHeight();

		for (const auto& [index, coordinates] : pictures.coordinates)
		{
			drawData = reinterpret_cast<LPARAM>(pictures.images->getImage(index));

			DrawStateW(deviceContext, NULL, nullptr, drawData, NULL, coordinates.first, coordinates.second, width, height, flags);
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

		if (pictures.coordinates.empty())
		{
			return BaseComposite::getStructure();
		}

		json::JSONBuilder builder = BaseComposite::getStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);
		vector<objectSmartPointer<jsonObject>> jsonCoordinates;

		pictures.images->loadBaseLoadableHolderStructure(current);

		for (const auto& [index, coordinates] : pictures.coordinates)
		{
			objectSmartPointer<jsonObject> object = json::utility::make_object<jsonObject>();

			object->data.push_back({ "x"s, static_cast<int64_t>(coordinates.first) });
			object->data.push_back({ "y"s, static_cast<int64_t>(coordinates.second) });

			json::utility::appendArray(move(object), jsonCoordinates);
		}

		current->getObject("imageHolder")->data.push_back({ "coordinates"s, move(jsonCoordinates) });

		return builder;
	}
}
