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

	private:
		std::filesystem::path pathToImage;
		std::any image;
		uint16_t imageWidth;
		uint16_t imageHeight;
		drawingType type;

	private:
		void drawImage();

	public:
		ImageButton(const std::wstring& buttonName, const std::filesystem::path& pathToImage, drawingType type, uint16_t imageWidth, uint16_t imageHeight, const utility::ComponentSettings& settings, BaseComposite* parent, const std::function<void()>& onClick = nullptr);

		ImageButton(const std::wstring& buttonName, const std::filesystem::path& pathToImage, drawingType type, uint16_t imageWidth, uint16_t imageHeight, const utility::ComponentSettings& settings, BaseComposite* parent, const std::string& functionName, const std::string& moduleName);

		void setImage(const std::filesystem::path& pathToImage, drawingType type, uint16_t imageWidth, uint16_t imageHeight);

		const std::filesystem::path& getPathToImage() const;

		uint16_t getImageWidth() const;

		uint16_t getImageHeight() const;

		drawingType getDrawingType() const;

		size_t getHash() const override;

		json::JSONBuilder getStructure() const override;

		~ImageButton();
	};
}
