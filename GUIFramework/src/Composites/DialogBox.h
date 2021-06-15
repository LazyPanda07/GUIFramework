#pragma once

#include "BaseComposites/BaseDialogBox.h"
#include "BaseComposites/BaseNonResizableComposite.h"
#include "Composites/AdditionalCreationData/AdditionalCreationData.h"

#undef DialogBox

namespace gui_framework
{
	class DialogBox :
		public BaseNonResizableComposite,
		public BaseDialogBox
	{
	public:
		class DialogBoxBuilder
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
				std::wstring text;
				RECT offsets;
				size_t typeHash;
				uint16_t width;
				uint16_t height;
				alignment type;
				std::any additionalData;

				builderComponentData(const std::wstring& componentName, const std::wstring& text, RECT&& offsets, size_t typeHash, uint16_t width, uint16_t height, alignment type, std::any&& additionalData);
			};

		private:
			utility::ComponentSettings settings;
			std::wstring className;
			std::wstring dialogBoxName;
			BaseComposite* parent;
			std::string functionName;
			std::vector<builderComponentData> components;

		public:
			DialogBoxBuilder(const std::wstring& className, const std::wstring& dialogBoxName, int x, int y);

			DialogBoxBuilder& clear();

			template<std::derived_from<BaseComponent> T>
			DialogBoxBuilder& addComponent(const std::wstring& componentName, uint16_t width, uint16_t height, alignment type, const utility::AdditionalCreationData<T>& additionalData = utility::AdditionalCreationData<T>(), int leftOffset = 0, int topOffset = 0, int rightOffset = 0, int bottomOffset = 0, const std::wstring& text = L"");

			DialogBoxBuilder& addDialogBoxFunction(const std::string& functionName);

			DialogBoxBuilder& addParent(BaseComposite* parent);

			/// @brief 
			/// @return
			/// @exception std::out_of_range Can't find creator for one of components 
			DialogBox* build() const;

			~DialogBoxBuilder() = default;
		};

	public:
		DialogBox(const std::wstring& className, const std::wstring& dialogBoxName, const utility::ComponentSettings& settings, BaseComponent* parent = nullptr, const std::string& dialogBoxFunctionName = "");

		~DialogBox() = default;
	};

	template<std::derived_from<BaseComponent> T>
	DialogBox::DialogBoxBuilder& DialogBox::DialogBoxBuilder::addComponent(const std::wstring& componentName, uint16_t width, uint16_t height, alignment type, const utility::AdditionalCreationData<T>& additionalData, int leftOffset, int topOffset, int rightOffset, int bottomOffset, const std::wstring& text)
	{
		if (settings.width < leftOffset + width + rightOffset + standard_sizes::dialogBoxBuilderMinWidth)
		{
			settings.width = leftOffset + width + rightOffset + standard_sizes::dialogBoxBuilderMinWidth;
		}

		settings.height += topOffset + height + bottomOffset;

		components.emplace_back(componentName, text, RECT(leftOffset, topOffset, rightOffset, bottomOffset), typeid(T).hash_code(), width, height, type, additionalData.getData());

		return *this;
	}
}
