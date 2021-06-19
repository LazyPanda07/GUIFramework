#pragma once

#include "BaseComponents/BaseComponent.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API BaseTabControl :
		virtual public BaseComponent
	{
	protected:
		HIMAGELIST imageList;
		std::unordered_map<std::wstring, uint16_t> images;

	public:
		BaseTabControl(const std::wstring& tabControlName, const utility::ComponentSettings& settings, BaseComponent* parent);

		virtual LRESULT append(const std::wstring& text) final;

		/// @brief 
		/// @param pathToImage 
		/// @return
		/// @exception gui_framework::exceptions::FileDoesNotExist
		virtual LRESULT append(const std::filesystem::path& pathToImage) final;

		/// @brief 
		/// @param text 
		/// @param pathToImage 
		/// @return
		/// @exception gui_framework::exceptions::FileDoesNotExist 
		virtual LRESULT append(const std::wstring& text, const std::filesystem::path& pathToImage) final;

		virtual size_t size() const final;

		virtual ~BaseTabControl();
	};
}
