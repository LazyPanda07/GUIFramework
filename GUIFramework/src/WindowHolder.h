#pragma once

#include "BaseComposites/BaseComposite.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API WindowHolder final
	{
	private:
		std::unique_ptr<BaseComposite> compositeWindow;

	public:
		/// @brief 
		/// @param windowFunctionName Value passed to CREATE_DEFAULT_WINDOW_FUNCTION
		WindowHolder(const std::wstring& compositeWindowClassName, const std::wstring& compositeWindowName, int x, int y, uint16_t width, uint16_t height, const std::string& windowFunctionName, bool isAsync = false);

		template<std::derived_from<BaseComposite> T>
		T* get();

		template<std::derived_from<BaseComposite> T>
		const T* get() const;

		template<>
		BaseComposite* get<BaseComposite>();

		template<>
		const BaseComposite* get<BaseComposite>() const;

		/// @brief Don't need in async mode
		/// @exception gui_framework::exceptions::GetLastErrorException
		void runMainLoop();

		~WindowHolder() = default;
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
