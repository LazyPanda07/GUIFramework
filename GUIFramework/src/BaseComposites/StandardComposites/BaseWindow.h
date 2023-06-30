#pragma once

#include "BaseComposites/BaseComposite.h"
#include "Holders/LoadableHolders/BaseLoadableHolder.h"
#include "Interfaces/Components/IComponentVisibility.h"

namespace gui_framework
{
	/// @brief Base class for composite windows
	class GUI_FRAMEWORK_API BaseWindow :
		public BaseComposite,
		public interfaces::IComponentVisibility
	{
	private:
		struct drawedImages
		{
			smartPointerType<utility::BaseLoadableHolder> images;
			std::unordered_map<uint16_t, std::pair<int, int>> coordinates;
			utility::BaseLoadableHolder::imageType type;

			drawedImages(smartPointerType<utility::BaseLoadableHolder>&& images, utility::BaseLoadableHolder::imageType type) noexcept;

			void addImage(BaseWindow* owner, int x, int y, const std::filesystem::path& pathToImage);

			void removeImage(const std::filesystem::path& pathToImage);
		};

	protected:
		std::unordered_map<std::string, drawedImages> pictures;

	public:
		/// @brief 
		/// @param moduleName Name of loaded resource module with icons
		/// @param smallIconResource Integer value from auto generated Visual Studio resources
		/// @param largeIconResource Integer value from auto generated Visual Studio resources
		BaseWindow(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, const interfaces::IStyles& styles, BaseComposite* parent = nullptr, const std::string& windowFunctionName = "", const std::string& moduleName = "", uint16_t smallIconResource = NULL, uint16_t largeIconResource = NULL);

		/// @brief Initialize block of pictures with same size
		/// @param pictureBlockName Name of pictures block
		/// @param imagesWidth Pictures width in pixels
		/// @param imagesHeight Pictures height in pixels
		/// @param type Holder's data type - BaseLoadableHolder::imageType::cursor doesn't support
		/// @exception std::runtime_error Wrong type value
		virtual void initDrawing(const std::string& pictureBlockName, uint16_t imagesWidth, uint16_t imagesHeight, utility::BaseLoadableHolder::imageType type) final;

		/// @brief Draw image in window
		/// @param pictureBlockName Name of pictures block
		/// @param x 
		/// @param y 
		/// @param pathToImage 
		/// @exception FileDoesNotExist
		/// @exception std::out_of_range 
		virtual void addImage(const std::string& pictureBlockName, int x, int y, const std::filesystem::path& pathToImage);

		/// @brief Remove image from window
		/// @param pictureBlockName Name of pictures block
		/// @param pathToImage 
		/// @exception std::out_of_range 
		virtual void removeImage(const std::string& pictureBlockName, const std::filesystem::path& pathToImage);

		/// @brief Clear window and draw all images
		virtual void drawAllImages() final;

		virtual void setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue) final override;

		/// @brief Used as key in creators
		/// @return typeid().hash_code()
		virtual size_t getHash() const override = 0;

		virtual json::JSONBuilder getStructure() const override;

		virtual ~BaseWindow() = default;
	};
}
