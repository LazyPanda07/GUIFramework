#pragma once

#include "pch.h"

#pragma comment (lib, "JSON.lib")
#pragma comment (lib, "Comctl32.lib")

namespace gui_framework
{
	/// @brief Singleton with GUIFramework settings
	class GUIFramework
	{
	private:
		INITCOMMONCONTROLSEX comm;

	private:
		GUIFramework();

		~GUIFramework() = default;

	public:
		static GUIFramework& get();

	};
}
