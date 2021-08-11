#pragma once

#include "pch.h"
#include "BaseComposites/BaseComposite.h"
#include "Utility/Holders/LoadableHolders/ImagesHolder.h"

namespace gui_framework
{
	/// @brief Base class for composite windows
	class GUI_FRAMEWORK_API BaseWindow : public BaseComposite
	{
	private:
		struct drawedImages
		{
			std::unique_ptr<utility::ImagesHolder> images;
			std::unordered_map<uint16_t, std::pair<int, int>> coordinates;

			void init(uint16_t imagesWidth, uint16_t imagesHeight);

			void addImage(BaseWindow* owner, int x, int y, const std::filesystem::path& pathToImage);

			void removeImage(const std::filesystem::path& pathToImage);
		};

	protected:
		drawedImages pictures;

	public:
		BaseWindow(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, const interfaces::IStyles& styles, BaseComponent* parent = nullptr, const std::string& windowFunctionName = "");

		virtual void initDrawing(uint16_t imagesWidth, uint16_t imagesHeight) final;

		/// @brief Draw image in window
		/// @param x 
		/// @param y 
		/// @param pathToImage 
		/// @exception FileDoesNotExist
		virtual void addImage(int x, int y, const std::filesystem::path& pathToImage);

		/// @brief Remove image from window
		/// @param pathToImage 
		/// @exception std::out_of_range
		virtual void removeImage(const std::filesystem::path& pathToImage);

		virtual json::JSONBuilder getStructure() const override;

		virtual ~BaseWindow() = default;
	};
}
