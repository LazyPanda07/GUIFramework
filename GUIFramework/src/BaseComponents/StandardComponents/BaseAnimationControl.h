#pragma once

#include "BaseComponents/BaseComponent.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API BaseAnimationControl : virtual public BaseComponent
	{
	public:
		BaseAnimationControl(const std::wstring& animationControlName, const utility::ComponentSettings& settings, BaseComponent* parent, bool isCentered = true, bool isAutoPlay = false);

		/// @brief 
		/// @param pathToAVIAnimationFile 
		/// @exception gui_framework::exceptions::FileDoesNotExist
		virtual bool openAnimation(const std::filesystem::path& pathToAVIAnimationFile) final;

		/// @brief 
		/// @param repeatCount A value of -1 means replay the animation indefinitely
		virtual bool playAnimation(int repeatCount = 0) final;

		virtual bool stopAnimation() final;

		virtual ~BaseAnimationControl() = default;
	};
}
