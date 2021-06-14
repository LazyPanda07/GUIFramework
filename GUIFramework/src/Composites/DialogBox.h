#pragma once

#include "BaseComposites/BaseDialogBox.h"
#include "BaseComposites/BaseNonResizableComposite.h"

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
				//TODO: pointer to creation function
				uint16_t width;
				uint16_t height;
				alignment type;

				builderComponentData(uint16_t width, uint16_t height, alignment type);
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
			void addComponent(uint16_t width, uint16_t height, alignment type);

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
	void DialogBox::DialogBoxBuilder::addComponent(uint16_t width, uint16_t height, alignment type)
	{
		components.emplace_back(width, height, type);
	}
}
