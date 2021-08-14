#include "pch.h"
#include "BaseLoadableHolder.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseLoadableHolder::imageData::imageData(uint16_t index, imageType type, any&& data) :
			index(index),
			type(type),
			data(move(data))
		{
			
		}

		BaseLoadableHolder::imageData::imageData(const imageData& other) :
			index(other.index),
			type(other.type),
			data(other.data)
		{
			const_cast<imageData&>(other).data.reset();
		}

		BaseLoadableHolder::imageData::imageData(imageData&& other) noexcept :
			index(other.index),
			type(other.type),
			data(move(other.data))
		{
			other.data.reset();
		}

		BaseLoadableHolder::imageData& BaseLoadableHolder::imageData::operator = (const imageData& other)
		{
			index = other.index;
			type = other.type;
			data = other.data;

			const_cast<imageData&>(other).data.reset();

			return *this;
		}

		BaseLoadableHolder::imageData& BaseLoadableHolder::imageData::operator = (imageData&& other) noexcept
		{
			index = other.index;
			type = other.type;
			data = move(other.data);

			other.data.reset();

			return *this;
		}

		BaseLoadableHolder::imageData::~imageData()
		{
			if (!data.has_value())
			{
				return;
			}

			switch (type)
			{
			case imageType::bitmap:
				DeleteObject(any_cast<HBITMAP>(data));

				break;
			case imageType::icon:
				DestroyIcon(any_cast<HICON>(data));

				break;
			case imageType::cursor:
				DestroyCursor(any_cast<HCURSOR>(data));

				break;
			}
		}

		json::JSONBuilder BaseLoadableHolder::getStructure() const
		{
			using json::utility::objectSmartPointer;
			using json::utility::jsonObject;

			uint32_t codepage = ISerializable::getCodepage();
			json::JSONBuilder builder(codepage);
			objectSmartPointer<jsonObject> object = json::utility::make_object<jsonObject>();
			vector<objectSmartPointer<jsonObject>> jsonImages;

			object->data.push_back({ "imagesWidth"s, static_cast<uint64_t>(imagesWidth) });
			object->data.push_back({ "imagesHeight"s, static_cast<uint64_t>(imagesHeight) });

			for (const auto& [path, data] : images)
			{
				objectSmartPointer<jsonObject> image = json::utility::make_object<jsonObject>();

				image->data.push_back({ "pathToImage"s, utility::to_string(path, codepage) });
				image->data.push_back({ "type"s, static_cast<uint64_t>(data.type) });

				json::utility::appendArray(move(image), jsonImages);
			}

			object->data.push_back({ "images"s, move(jsonImages) });

			builder.append("imageHolder"s, move(object));

			return builder;
		}

		uint16_t BaseLoadableHolder::insertImage(const filesystem::path& pathToImage, imageType type)
		{
			HBITMAP image = static_cast<HBITMAP>(LoadImageW(nullptr, pathToImage.wstring().data(), static_cast<uint32_t>(type), imagesWidth, imagesHeight, LR_LOADFROMFILE));
			uint16_t resultIndex;

			switch (type)
			{
			case imageType::bitmap:
				resultIndex = images.emplace(pathToImage, imageData(ImageList_Add(imageList, image, NULL), type, image)).first->second.index;

				break;
			case imageType::icon:
				resultIndex = images.emplace(pathToImage, imageData(ImageList_AddIcon(imageList, reinterpret_cast<HICON>(image)), type, image)).first->second.index;

				break;
			case imageType::cursor:
				resultIndex = images.emplace(pathToImage, imageData(ImageList_AddIcon(imageList, reinterpret_cast<HCURSOR>(image)), type, image)).first->second.index;

				break;

			default:
				resultIndex = static_cast<uint16_t>(-1);

				DeleteObject(image);

				break;
			}

			return resultIndex;
		}

		BaseLoadableHolder::BaseLoadableHolder(uint16_t imagesWidth, uint16_t imagesHeight, size_t count) :
			imageList(ImageList_Create(imagesWidth, imagesHeight, ILC_COLOR32, 0, static_cast<int>(count))),
			imagesWidth(imagesWidth),
			imagesHeight(imagesHeight)
		{

		}

		void BaseLoadableHolder::removeImage(const filesystem::path& pathToImage)
		{
			auto it = images.find(pathToImage);

			if (it != images.end())
			{
				ImageList_Remove(imageList, it->second.index);

				images.erase(it);
			}
		}

		void BaseLoadableHolder::removeImage(uint16_t imageIndex)
		{
			for (const auto& [key, value] : images)
			{
				if (value.index == imageIndex)
				{
					images.erase(key);

					ImageList_Remove(imageList, imageIndex);

					break;
				}
			}
		}

		bool BaseLoadableHolder::contains(const filesystem::path& pathToImage) const
		{
			return images.contains(pathToImage);
		}

		uint16_t BaseLoadableHolder::getImagesWidth() const
		{
			return imagesWidth;
		}

		uint16_t BaseLoadableHolder::getImagesHeight() const
		{
			return imagesHeight;
		}

		uint16_t BaseLoadableHolder::getImageIndex(const filesystem::path& pathToImage) const
		{
			return images.at(pathToImage).index;
		}

		BaseLoadableHolder::imageType BaseLoadableHolder::getImageType(const filesystem::path& pathToImage) const
		{
			return images.at(pathToImage).type;
		}

		BaseLoadableHolder::imageType BaseLoadableHolder::getImageType(uint16_t imageIndex) const
		{
			for (const auto& [key, value] : images)
			{
				if (value.index == imageIndex)
				{
					return value.type;
				}
			}

			throw out_of_range(format("Can't find imageType at {} index", imageIndex));
		}

		HIMAGELIST BaseLoadableHolder::getImageList() const
		{
			return imageList;
		}

		uint16_t BaseLoadableHolder::operator [] (const filesystem::path& pathToImage) const
		{
			return images.at(pathToImage).index;
		}

		filesystem::path BaseLoadableHolder::operator [] (uint16_t index) const
		{
			for (const auto& [key, value] : images)
			{
				if (value.index == index)
				{
					return key;
				}
			}

			throw out_of_range(format("Can't find image at {} index", index));
		}

		iterators::loadable_forward_iterator BaseLoadableHolder::begin() noexcept
		{
			vector<filesystem::path> imagesPaths;

			imagesPaths.reserve(images.size());

			for (const auto& [path, data] : images)
			{
				imagesPaths.push_back(path);
			}

			return iterators::loadable_forward_iterator(move(imagesPaths), 0);
		}

		iterators::loadable_const_forward_iterator BaseLoadableHolder::cbegin() const noexcept
		{
			vector<filesystem::path> imagesPaths;

			imagesPaths.reserve(images.size());

			for (const auto& [path, data] : images)
			{
				imagesPaths.push_back(path);
			}

			return iterators::loadable_const_forward_iterator(move(imagesPaths), 0);
		}

		iterators::loadable_forward_iterator BaseLoadableHolder::end() noexcept
		{
			return iterators::loadable_forward_iterator({}, images.size());
		}

		iterators::loadable_const_forward_iterator BaseLoadableHolder::cend() const noexcept
		{
			return iterators::loadable_const_forward_iterator({}, images.size());
		}

		void BaseLoadableHolder::loadBaseLoadableHolderStructure(json::utility::objectSmartPointer<json::utility::jsonObject>& current) const
		{
			current->data.push_back({ "imageHolder"s,  move(this->getStructure()["imageHolder"]) });
		}

		BaseLoadableHolder::~BaseLoadableHolder()
		{
			ImageList_Destroy(imageList);
		}
	}
}
