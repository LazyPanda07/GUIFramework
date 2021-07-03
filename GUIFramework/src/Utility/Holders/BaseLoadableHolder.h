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

		class GUI_FRAMEWORK_API BaseLoadableHolder
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

		protected:
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

			virtual ~BaseLoadableHolder();
		};
	}
}
