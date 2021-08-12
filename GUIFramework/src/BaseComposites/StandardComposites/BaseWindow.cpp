#include "pch.h"
#include "BaseWindow.h"

#include "Exceptions/FileDoesNotExist.h"

#include "Utility/Paint/DrawImage.h"

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

		utility::paint::drawImageByPath(owner, *images, x, y, pathToImage);
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
		if (!filesystem::exists(pathToImage))
		{
			throw exceptions::FileDoesNotExist(pathToImage);
		}

		pictures.addImage(this, x, y, pathToImage);
	}

	void BaseWindow::removeImage(const filesystem::path& pathToImage)
	{
		pictures.removeImage(pathToImage);

		InvalidateRect(nullptr, nullptr, true);
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
