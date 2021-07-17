#pragma once

#include "BaseComposites/BaseComposite.h"

namespace gui_framework
{
	/// @brief Provides runMainLoop for top level window
	class GUI_FRAMEWORK_API WindowHolder final
	{
	private:
		std::unique_ptr<BaseComposite> compositeWindow;
		bool unregisterClass;

	public:
		/// @brief 
		/// @param compositeWindow 
		/// @param clearClass Unregister class after window destroy
		WindowHolder(std::unique_ptr<BaseComposite>&& compositeWindow, bool unregisterClass = false) noexcept;

		template<std::derived_from<BaseComposite> T>
		T* getDerived();

		template<std::derived_from<BaseComposite> T>
		const T* getDerived() const;

		BaseComposite* get();

		const BaseComposite* get() const;

		/// @brief Process messages. Must be called after initialization
		/// @param registeredHotkeyIds You may pass all registered hotkeys for unregister them after window destroy
		/// @exception GetLastErrorException 
		void runMainLoop(const std::vector<uint32_t>& registeredHotkeyIds = {});

		~WindowHolder();
	};

	template<std::derived_from<BaseComposite> T>
	T* WindowHolder::getDerived()
	{
		return static_cast<T*>(compositeWindow.get());
	}

	template<std::derived_from<BaseComposite> T>
	const T* WindowHolder::getDerived() const
	{
		return static_cast<T*>(compositeWindow.get());
	}
}
