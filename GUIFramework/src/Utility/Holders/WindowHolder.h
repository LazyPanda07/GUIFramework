#pragma once

#include "headers.h"
#include "BaseComposites/BaseComposite.h"
#include "BaseComposites/StandardComposites/BaseDialogBox.h"

namespace gui_framework
{
	/// @brief Provides runMainLoop for top level window
	class GUI_FRAMEWORK_API WindowHolder final
	{
	private:
		std::unique_ptr<BaseComposite> compositeWindow;
		bool unregisterClass;

		WindowHolder(BaseDialogBox* dialogBox);

	public:
		/// @brief 
		/// @param compositeWindow 
		/// @param clearClass Unregister class after window destroy
		WindowHolder(std::unique_ptr<BaseComposite>&& compositeWindow, bool unregisterClass = false) noexcept;

		template<std::derived_from<BaseComposite> T>
		T* get();

		template<std::derived_from<BaseComposite> T>
		const T* get() const;

		BaseComposite* get();

		const BaseComposite* get() const;

		/// @brief Process messages. Must be called after initialization
		/// @param registeredHotkeyIds You may pass all registered hotkeys for unregister them after window destroy
		/// @exception GetLastErrorException 
		int runMainLoop(const std::vector<uint32_t>& registeredHotkeyIds = {});

		~WindowHolder();

		friend class BaseDialogBox;
	};

	template<std::derived_from<BaseComposite> T>
	T* WindowHolder::get()
	{
		return static_cast<T*>(compositeWindow.get());
	}

	template<std::derived_from<BaseComposite> T>
	const T* WindowHolder::get() const
	{
		return static_cast<T*>(compositeWindow.get());
	}
}
