#pragma once

#include "headers.h"
#include "BaseComposites/StandardComposites/BaseDialogBox.h"
#include "Interfaces/Components/INonResizableComponent.h"

#undef DialogBox

namespace gui_framework
{
	/// @brief Standard dialog box
	class GUI_FRAMEWORK_API DialogBox :
		public BaseDialogBox,
		public interfaces::INonResizableComponent
	{
	public:
		/// @brief Builder for dialog boxes
		class GUI_FRAMEWORK_API DialogBoxBuilder
		{
		public:
			enum class alignment
			{
				left,
				center,
				right
			};

		private:
			struct builderComponentData
			{
				std::wstring componentName;
				RECT offsets;
				size_t typeHash;
				utility::ComponentSettings settings;
				alignment type;
				std::any additionalData;

				builderComponentData(const std::wstring& componentName, const interfaces::IStyles& styles, RECT&& offsets, size_t typeHash, uint16_t width, uint16_t height, alignment type, std::any&& additionalData);
			};

		private:
			utility::ComponentSettings settings;
			std::wstring className;
			std::wstring dialogBoxName;
			BaseComposite* parent;
			std::string functionName;
			std::vector<builderComponentData> components;
			std::string moduleName;
			uint16_t smallIconResource;
			uint16_t largeIconResource;

		public:
			/// @brief 
			/// @param moduleName Name of loaded resource module with icons
			/// @param smallIconResource Integer value from auto generated Visual Studio resources
			/// @param largeIconResource Integer value from auto generated Visual Studio resources
			DialogBoxBuilder(const std::wstring& className, const std::wstring& dialogBoxName, int x, int y, const std::string& dialogBoxFunctionName, const std::string& moduleName = "", uint16_t smallIconResource = NULL, uint16_t largeIconResource = NULL);

			DialogBoxBuilder& clear();

			template<std::derived_from<BaseComponent> T>
			DialogBoxBuilder& addComponent(const std::wstring& componentName, uint16_t width, uint16_t height, alignment type, const utility::AdditionalCreationData<T>& additionalData = utility::AdditionalCreationData<T>(), int leftOffset = 0, int topOffset = 0, int rightOffset = 0, int bottomOffset = 0, const interfaces::IStyles& styles = interfaces::IStyles());

			DialogBoxBuilder& addParent(BaseComposite* parent);

			/// @brief 
			/// @return
			/// @exception std::out_of_range Can't find creator for one of components 
			DialogBox* build() const;

			~DialogBoxBuilder() = default;
		};

	public:
		/// @brief 
		/// @param moduleName Name of loaded resource module with icons
		/// @param smallIconResource Integer value from auto generated Visual Studio resources
		/// @param largeIconResource Integer value from auto generated Visual Studio resources
		DialogBox(const std::wstring& className, const std::wstring& dialogBoxName, const utility::ComponentSettings& settings, BaseComponent* parent = nullptr, const std::string& dialogBoxFunctionName = "", const std::string& moduleName = "", uint16_t smallIconResource = NULL, uint16_t largeIconResource = NULL);

		size_t getHash() const override;

		~DialogBox() = default;
	};

	template<std::derived_from<BaseComponent> T>
	DialogBox::DialogBoxBuilder& DialogBox::DialogBoxBuilder::addComponent(const std::wstring& componentName, uint16_t width, uint16_t height, alignment type, const utility::AdditionalCreationData<T>& additionalData, int leftOffset, int topOffset, int rightOffset, int bottomOffset, const interfaces::IStyles& styles)
	{
		if (settings.width < leftOffset + width + rightOffset + standard_sizes::dialogBoxBuilderMinWidth)
		{
			settings.width = leftOffset + width + rightOffset + standard_sizes::dialogBoxBuilderMinWidth;
		}

		settings.height += topOffset + height + bottomOffset;

		components.emplace_back(componentName, styles, RECT(leftOffset, topOffset, rightOffset, bottomOffset), typeid(T).hash_code(), width, height, type, additionalData.getData());

		return *this;
	}
}
