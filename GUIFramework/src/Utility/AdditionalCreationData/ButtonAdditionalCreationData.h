#pragma once

#include "Core.h"
#include "AdditionalCreationData.h"
#include "Components/Buttons/Button.h"
#include "Components/Buttons/CheckBox.h"
#include "Components/Buttons/ImageButton.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Specialization for Button
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<Button>
		{
		protected:
			std::wstring text;
			std::function<void()> onClick;
			std::string onClickFunctionName;
			std::string onClickFunctionModule;

		public:
			AdditionalCreationData() = default;

			AdditionalCreationData(const std::wstring text, const std::function<void()>& onClick);

			AdditionalCreationData(const std::wstring text, const std::string& onClickFunctionName, const std::string& onClickFunctionModule);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};

		/// @brief Specialization for CheckBox
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<CheckBox>
		{
		protected:
			std::wstring text;
			std::function<void()> onCheck;
			std::function<void()> onClear;
			std::function<void()> onClick;
			std::string onCheckFunctionName;
			std::string onCheckFunctionModule;
			std::string onClearFunctionName;
			std::string onClearFunctionModule;
			std::string onClickFunctionName;
			std::string onClickFunctionModule;

		public:
			AdditionalCreationData() = default;

			AdditionalCreationData(const std::wstring text, const std::function<void()>& onCheck, const std::function<void()>& onClear, const std::function<void()>& onClick = nullptr);

			AdditionalCreationData(const std::wstring text, const std::string& onCheckFunctionName, const std::string& onCheckFunctionModule, const std::string& onClearFunctionName, const std::string& onClearFunctionModule, const std::string& onClickFunctionName = "", const std::string& onClickFunctionModule = "");

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};

		/// @brief Specialization for ImageButton
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<ImageButton>
		{
		protected:
			std::wstring text;
			std::filesystem::path pathToImage;
			uint16_t imageWidth;
			uint16_t imageHeight;
			ImageButton::drawingType type;
			std::function<void()> onClick;
			std::string onClickFunctionName;
			std::string onClickFunctionModule;

		public:
			AdditionalCreationData() = default;

			AdditionalCreationData(const std::wstring& text, const std::filesystem::path& pathToImage, uint16_t imageWidth, uint16_t imageHeight, ImageButton::drawingType type, const std::function<void()>& onClick);

			AdditionalCreationData(const std::wstring& text, const std::filesystem::path& pathToImage, uint16_t imageWidth, uint16_t imageHeight, ImageButton::drawingType type, const std::string& onClickFunctionName, const std::string& onClickFunctionModule);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};
	}
}
