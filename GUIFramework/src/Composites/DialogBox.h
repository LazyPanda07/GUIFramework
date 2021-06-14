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

			void clear();

			template<std::derived_from<BaseComponent> T>
			void addComponent(const std::wstring& componentName, uint16_t width, uint16_t height, alignment type, const utility::AdditionalCreationData<T>& additionalData, int leftOffset = 0, int topOffset = 0, int rightOffset = 0, int bottomOffset = 0, const std::wstring& text = L"");

			void addDialogBoxFunction(const std::string& functionName);

			void addParent(BaseComposite* parent);

			DialogBox* build() const;

			~DialogBoxBuilder() = default;
		};

	public:
		DialogBox(const std::wstring& className, const std::wstring& dialogBoxName, const utility::ComponentSettings& settings, BaseComponent* parent = nullptr, const std::string& dialogBoxFunctionName = "");

		~DialogBox() = default;
	};

	template<std::derived_from<BaseComponent> T>
	void DialogBox::DialogBoxBuilder::addComponent(const std::wstring& componentName, uint16_t width, uint16_t height, alignment type, const utility::AdditionalCreationData<T>& additionalData, int leftOffset, int topOffset, int rightOffset, int bottomOffset, const std::wstring& text)
	{
		if (settings.width < width + leftOffset + rightOffset)
		{
			settings.width = width + leftOffset + rightOffset;
		}

		if (settings.height < height + topOffset + bottomOffset)
		{
			settings.height = height + topOffset + bottomOffset;
		}

		components.emplace_back(componentName, text, RECT(leftOffset, topOffset, rightOffset, bottomOffset), typeid(T).hash_code(), width, height, type, additionalData.getData());
	}
}
