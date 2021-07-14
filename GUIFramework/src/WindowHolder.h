#pragma once

#include "BaseComposites/BaseComposite.h"

namespace gui_framework
{
	/// @brief Provides runMainLoop for top level window
	class GUI_FRAMEWORK_API WindowHolder final
	{
	private:
		std::unique_ptr<BaseComposite> compositeWindow;

	public:
		WindowHolder(std::unique_ptr<BaseComposite>&& compositeWindow) noexcept;

		template<std::derived_from<BaseComposite> T>
		T* getDerived();

		template<std::derived_from<BaseComposite> T>
		const T* getDerived() const;

		BaseComposite* get();

		const BaseComposite* get() const;

		/// @brief 
		/// @exception GetLastErrorException
		void runMainLoop();

		~WindowHolder() = default;
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
