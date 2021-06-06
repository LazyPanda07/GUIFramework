#pragma once

#include "BaseComponents/BaseComponent.h"
#include "Interfaces/Components/IResizableComponent.h"

namespace gui_framework
{
	class BaseComboBox :
		virtual public BaseComponent,
		public interfaces::IResizableComponent
	{
	protected:
		SIZE requiredSize;

	public:
		enum class itemHeightEnum
		{
			forAllItems,
			selectionFieldItem
		};

	public:
		BaseComboBox(const std::wstring& comboBoxName, const utility::ComponentSettings& settings, BaseComponent* parent);

		virtual LRESULT addValue(const std::wstring& value) final;

		virtual LRESULT removeValue(size_t index) final;

		virtual LRESULT insertValue(const std::wstring& value, LRESULT index);

		virtual LRESULT changeValue(const std::wstring& newValue, LRESULT index);

		virtual std::wstring findSubString(const std::wstring& subStringToFind) final;

		virtual std::wstring findString(const std::wstring& stringToFind) final;

		virtual std::wstring getValue(size_t index) const final;

		virtual LRESULT getCurrentSelectionIndex() const final;

		virtual LRESULT setCurrentSelection(LRESULT index) const final;

		virtual LRESULT size() const final;

		virtual void clear() final;

		virtual LRESULT setItemHeight(itemHeightEnum value, uint16_t height) final;

		virtual LRESULT setDroppedWidth(uint16_t width) final;

		virtual LRESULT getItemHeight(itemHeightEnum value) const final;

		virtual LRESULT getDroppedWidth() const final;

		virtual void resize(uint16_t width, uint16_t height) override;

		virtual ~BaseComboBox() = default;
	};
}
