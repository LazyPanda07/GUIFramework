#pragma once

#include "BaseComposites/StandardComposites/BaseMainWindow.h"
#include "Deserializers/Composites/MainWindowDeserializer.h"

namespace gui_framework
{
	/// @brief Used for recreation windowed application from JSON
	class GUI_FRAMEWORK_API Recreator
	{
	private:
		json::JSONParser windowedApplicationStructure;

	public:
		Recreator(const std::filesystem::path& pathToJSON);

		Recreator(const std::string& json);

		template<typename MainWindowT, typename... Args> requires (std::is_base_of_v<BaseMainWindow, MainWindowT>)
		std::unique_ptr<MainWindowT> deserialize(Args&&... args) const;

		~Recreator() = default;
	};

	template<typename MainWindowT, typename... Args> requires (std::is_base_of_v<BaseMainWindow, MainWindowT>)
	std::unique_ptr<MainWindowT> Recreator::deserialize(Args&&... args) const
	{
		const auto& [componentName, description] = *windowedApplicationStructure.begin();
		std::unique_ptr<MainWindowT> mainWindow = std::make_unique<MainWindowT>(std::forward<Args>(args)...);

		deserializers::MainWindowDeserializer().deserialize(componentName, get<json::utility::jsonObject>(description), mainWindow);

		return mainWindow;
	}
}
