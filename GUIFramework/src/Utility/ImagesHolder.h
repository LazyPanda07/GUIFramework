#pragma once

#include "pch.h"

namespace gui_framework
{
	namespace utility
	{
		enum class iconListViewType : uint32_t
		{
			icon,
			smallIcon = 2
		};

		class GUI_FRAMEWORK_API ImagesHolder final
		{
		public:
			enum class imageType : uint32_t
			{
				bitmap,
				icon,
				cursor
			};

		private:
			struct imageData
			{
				uint16_t index;
				imageType type;

				imageData(uint16_t index, imageType type);

				imageData(const imageData& other) = default;

				imageData(imageData&& other) noexcept = default;

				imageData& operator = (const imageData& other) = default;

				imageData& operator = (imageData&& other) noexcept = default;

				~imageData() = default;
			};

		private:
			HIMAGELIST imageList;
			std::unordered_map<std::wstring, imageData> images;
			uint16_t imagesWidth;
			uint16_t imagesHeight;

		public:
			ImagesHolder(uint16_t imagesWidth, uint16_t imagesHeight, size_t count = standard_sizes::defaultImagesCount);

			/// @brief 
			/// @param pathToImage 
			/// @return Index of newly added image
			uint16_t addImage(const std::filesystem::path& pathToImage, imageType type);

			void removeImage(const std::filesystem::path& pathToImage);

			void removeImage(uint16_t imageIndex);

			bool contains(const std::filesystem::path& pathToImage) const;

			uint16_t getImagesWidth() const;

			uint16_t getImagesHeight() const;

			/// @brief 
			/// @param pathToImage 
			/// @return
			/// @exception std::out_of_range 
			uint16_t getImageIndex(const std::filesystem::path& pathToImage) const;

			imageType getImageType(const std::filesystem::path& pathToImage) const;

			/// @brief 
			/// @param imageIndex 
			/// @return
			/// @exception std::out_of_range 
			imageType getImageType(uint16_t imageIndex) const;

			HIMAGELIST getImageList() const;

			/// @brief 
			/// @param pathToImage 
			/// @return 
			/// @exception std::out_of_range
			uint16_t operator [] (const std::filesystem::path& pathToImage) const;

			~ImagesHolder();
		};
	}
}
