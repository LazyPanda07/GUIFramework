#pragma once

#include "BaseComponents/StandardComponents/Buttons/BaseButton.h"
#include "Interfaces/Components/IResizableComponent.h"

namespace gui_framework
{
	/// @brief Button with image
	class GUI_FRAMEWORK_API ImageButton : 
		public BaseButton,
		public interfaces::IResizableComponent
	{
	public:
		enum class drawingType
		{
			image,
			text,
			textAndImage
		};

		using imageType = utility::BaseLoadableHolder::imageType;

	private:
		std::filesystem::path pathToImage;
		std::any image;
		std::string resourceModuleName;
		drawingType dType;
		imageType iType;
		uint32_t imageResource;
		uint16_t imageWidth;
		uint16_t imageHeight;

	private:
		void drawImage();

	public:
		ImageButton(const std::wstring& buttonName, const std::filesystem::path& pathToImage, drawingType dType, imageType iType, uint16_t imageWidth, uint16_t imageHeight, const utility::ComponentSettings& settings, BaseComposite* parent, const std::function<void()>& onClick = nullptr);

		ImageButton(const std::wstring& buttonName, const std::filesystem::path& pathToImage, drawingType dType, imageType iType, uint16_t imageWidth, uint16_t imageHeight, const utility::ComponentSettings& settings, BaseComposite* parent, const std::string& functionName, const std::string& moduleName);

		ImageButton(const std::wstring& buttonName, uint32_t imageResources, drawingType dType, imageType iType, uint16_t imageWidth, uint16_t imageHeight, const utility::ComponentSettings& settings, BaseComposite* parent, const std::function<void()>& onClick = nullptr, const std::string& resourceModuleName = "");

		ImageButton(const std::wstring& buttonName, uint32_t imageResources, drawingType dType, imageType iType, uint16_t imageWidth, uint16_t imageHeight, const utility::ComponentSettings& settings, BaseComposite* parent, const std::string& functionName, const std::string& moduleName, const std::string& resourceModuleName = "");

		void setImage(const std::filesystem::path& pathToImage, drawingType dType, imageType iType, uint16_t imageWidth, uint16_t imageHeight);

		void setImage(uint32_t imageResource, drawingType dType, imageType iType, uint16_t imageWidth, uint16_t imageHeight, const std::string& resourceModuleName);

		const std::filesystem::path& getPathToImage() const;

		uint16_t getImageWidth() const;

		uint16_t getImageHeight() const;

		drawingType getDrawingType() const;

		imageType getImageType() const;

		size_t getHash() const override;

		json::JSONBuilder getStructure() const override;

		~ImageButton();
	};
}
