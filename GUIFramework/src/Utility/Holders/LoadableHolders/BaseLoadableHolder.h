#pragma once

#include "core.h"
#include "Interfaces/Iterators/IIterable.h"
#include "Interfaces/Utility/ISerializable.h"
#include "Iterators/loadable_forward_iterator.h"
#include "Iterators/loadable_const_forward_iterator.h"

namespace gui_framework
{
	namespace utility
	{
		enum class iconListViewType : uint32_t
		{
			icon,
			smallIcon = 2
		};

		/// @brief Base class for all visual asset loaders
		class GUI_FRAMEWORK_API BaseLoadableHolder :
			public interfaces::IIterable<std::filesystem::path, iterators::loadable_forward_iterator, iterators::loadable_const_forward_iterator>,
			public interfaces::ISerializable
		{
		public:
			enum class imageType : uint32_t
			{
				bitmap,
				icon,
				cursor
			};

		protected:
			struct imageData
			{
				uint16_t index;
				imageType type;
				std::any data;

				imageData(uint16_t index, imageType type, std::any&& data);

				imageData(const imageData& other);

				imageData(imageData&& other) noexcept;

				imageData& operator = (const imageData& other);

				imageData& operator = (imageData&& other) noexcept;

				~imageData();
			};

		private:
			virtual json::JSONBuilder getStructure() const final override;

		protected:
			HIMAGELIST imageList;
			std::unordered_map<std::wstring, imageData> images;
			uint16_t imagesWidth;
			uint16_t imagesHeight;

		protected:
			virtual uint16_t insertImage(const std::filesystem::path& pathToImage, imageType type) final;

		public:
			BaseLoadableHolder(uint16_t imagesWidth, uint16_t imagesHeight, size_t count = standard_sizes::defaultImagesCount);

			virtual uint16_t addImage(const std::filesystem::path& pathToImage) = 0;

			virtual void removeImage(const std::filesystem::path& pathToImage) final;

			virtual void removeImage(uint16_t imageIndex) final;

			virtual bool contains(const std::filesystem::path& pathToImage) const final;

			virtual uint16_t getImagesWidth() const final;

			virtual uint16_t getImagesHeight() const final;

			/// @brief 
			/// @param pathToImage 
			/// @return
			/// @exception std::out_of_range 
			virtual uint16_t getImageIndex(const std::filesystem::path& pathToImage) const final;

			virtual imageType getImageType(const std::filesystem::path& pathToImage) const final;

			/// @brief 
			/// @param imageIndex 
			/// @return
			/// @exception std::out_of_range 
			virtual imageType getImageType(uint16_t imageIndex) const final;

			virtual HIMAGELIST getImageList() const final;

			/// @brief 
			/// @param pathToImage 
			/// @return 
			/// @exception std::out_of_range
			virtual uint16_t operator [] (const std::filesystem::path& pathToImage) const final;

			/// @brief 
			/// @param index 
			/// @return 
			/// @exception std::out_of_range
			virtual std::filesystem::path operator [] (uint16_t index) const final;

			/// @brief Can't be modified
			virtual iterators::loadable_forward_iterator begin() noexcept final override;

			virtual iterators::loadable_const_forward_iterator cbegin() const noexcept final override;
 
			virtual iterators::loadable_forward_iterator end() noexcept final override;

			virtual iterators::loadable_const_forward_iterator cend() const noexcept final override;

			virtual std::pair<std::string, json::utility::jsonObject::variantType>& loadBaseLoadableHolderStructure(json::utility::jsonObject& current) const final;

			virtual ~BaseLoadableHolder();
		};
	}
}
