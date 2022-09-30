#pragma once

#include "Core.h"

#include "Interfaces/Utility/ISerializable.h"

namespace gui_framework
{
	namespace interfaces
	{
		/// @brief Interface for all menu items
		class GUI_FRAMEWORK_API IMenuItem : public ISerializable
		{
		protected:
			std::wstring text;
			std::string type;
			HMENU parent;
			uint32_t index;

		public:
			IMenuItem(const std::wstring& text, const std::string& type);

			virtual void processMessage() = 0;

			/// @brief 
			/// @return styles - new item value 
			virtual std::tuple<uint32_t, uint64_t> getCreationData() const = 0;

			virtual void createMenuItem(HMENU parent) final;

			virtual void setParent(HMENU parent) final;

			virtual void setIndex(uint32_t index) final;

			virtual const std::wstring& getText() const final;

			virtual const std::string& getType() const final;

			virtual json::JSONBuilder getStructure() const override;

			virtual ~IMenuItem();
		};
	}
}
